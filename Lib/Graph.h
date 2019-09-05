#ifndef GRAPH_H
#define GRAPH_H
#include "Object.h"
#include "SharedPointer.h"
#include "DynamicArray.h"
#include "LinkQueue.h"
#include "LinkStack.h"
#include "Array.h"

namespace Lib
{

template <typename E>
struct Edge : public Object
{
    int b;
    int e;
    E data;

    Edge(int i = -1, int j = -1)
    {
        b = i;
        e = j;
    }

    Edge(int i, int j, const E& value)
    {
        b = i;
        e = j;
        data = value;
    }

    bool operator ==(const Edge<E>& obj)
    {
        return (b == obj.b) && (e = obj.e);
    }

    bool operator !=(const Edge<E>& obj)
    {
        return !(*this == obj);
    }
};
//V与顶点相关的数据元素的类型，E与边相关的数据元素的类型
template <typename V, typename E>
class Graph : public Object
{
protected:
    template <typename T>
    //将队列转化为数组
    DynamicArray<T>* toArray(LinkQueue<T>& queue)
    {
        DynamicArray<T>* ret = new DynamicArray<T>(queue.length());

        if(ret != NULL)
        {
            for(int i = 0; i < ret->length(); i++,queue.remove())
            {
                ret->set(i, queue.front());
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create ret object...");
        }

        return ret;
    }
public:
    virtual V getVertex(int i) = 0;
    virtual bool getVertex(int i, V& value) = 0;
    virtual bool setVertex(int i, const V& value) = 0;
    virtual SharedPointer< Array<int> > getAdjacent(int i) = 0;
    virtual bool isAdjacent(int i, int j) = 0;
    virtual E getEdge(int i, int j) = 0;
    virtual bool getEdge(int i, int j, E& value) = 0;
    virtual bool setEdge(int i, int j, const E& value) = 0;
    virtual bool removeEdge(int i, int j) = 0;
    virtual int vCount() = 0;
    virtual int eCount() = 0;
    virtual int OD(int i) = 0;
    virtual int ID(int i) = 0;
    virtual int TD(int i)
    {
        return OD(i) + ID(i);
    }

    bool asUndirected()
    {
        bool ret = true;

        for(int i = 0; i < vCount(); i++)
        {
            for(int j = 0; j < vCount(); j++)
            {
                if(isAdjacent(i, j))
                {
                    ret = ret && isAdjacent(j, i) && (getEdge(i, j) == getEdge(j, i));
                }
            }
        }

        return ret;
    }

    //最小生成树算法prim
    SharedPointer < Array< Edge<E> > > prim(const E& LIMIT)
    {
        //E集合
        LinkQueue< Edge<E> > ret;
        //判断是否是无向图，因为prim算法只适用于无向图
        if( asUndirected() )
        {
            DynamicArray<int> adjVex(vCount());
            DynamicArray<bool> mark(vCount());
            DynamicArray<E> cost(vCount());
            SharedPointer< Array<int> > aj = NULL;
            bool end = false;
            int v = 0;

            for(int i = 0; i < vCount(); i++)
            {
                adjVex[i] = -1;
                mark[i] = false;
                cost[i] = LIMIT;
            }

            mark[v] = true;

            aj = getAdjacent(v);

            for(int j = 0; j < aj->length(); j++)
            {
                cost[(*aj)[j]] = getEdge(v, (*aj)[j]);
                //权值所对应的边
                adjVex[(*aj)[j]] = v;
            }

            //最多循环n次，也就是顶点的数目
            for(int i = 0; (i < vCount()) && !end; i++)
            {
                E m = LIMIT;
                int k = -1;
                for(int j = 0; j < vCount(); j++)
                {
                    if(!mark[j] && (cost[j] < m))
                    {
                        m = cost[j];
                        k = j;
                    }
                }

                end = (k == -1);

                if(!end)
                {
                    ret.add(Edge<E>(adjVex[k], k, getEdge(adjVex[k], k)));

                    //标记顶点进入了T集合
                    mark[k] = true;

                    aj = getAdjacent(k);

                    for(int j = 0; j < aj->length(); j++)
                    {
                        if( !mark[(*aj)[j]] && (getEdge(k, (*aj)[j]) < cost[(*aj)[j]]))
                        {
                            cost[(*aj)[j]] = getEdge(k, (*aj)[j]);
                            adjVex[(*aj)[j]] = k;
                        }
                    }
                }
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "Prim operation is for undirested graph only...");
        }

        if(ret.length() != (vCount() - 1))
        {
            THROW_EXCEPTION(InvalidOperationException, "No enough edge for prim operation...");
        }

        return toArray(ret);
    }


    //参数为起始顶点的编号,图的广度优先遍历
    SharedPointer< Array<int> > BFS(int i)
    {
        DynamicArray<int>* ret = NULL;

        if((0 <= i) && (i < vCount()))
        {
            LinkQueue<int> q;
            LinkQueue<int> r;
            DynamicArray<bool> visited(vCount());

            //标记数组初始化
            for(int i = 0; i < visited.length(); i++)
            {
                visited[i] = false;
            }
            //将图中元素i放入q队列中
            q.add(i);

            while(q.length() > 0)
            {
                //取得对头队头元素
                int v = q.front();

                q.remove();
                //查看对头元素是否被访问过，如果没被访问过则将其邻接顶点压入队列中
                if(!visited[v])
                {
                    SharedPointer< Array<int> > aj = getAdjacent(v);

                    for(int j = 0; j < aj->length(); j++)
                    {
                        q.add((*aj)[j]);
                    }

                    //将元素v放入到r队列中
                    r.add(v);
                    visited[v] = true;
                }
            }
            //将返回值队列转化为数组
            ret = toArray(r);
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Index i is invalid...");
        }

        return ret;
    }

    //图的深度优先遍历
    SharedPointer< Array<int> > DFS(int i)
    {
        //存储遍历结果值的数组
        DynamicArray<int>* ret = NULL;

        if((0 <= i) && (i < vCount()))
        {
            LinkStack<int> s;
            LinkQueue<int> r;
            //标记数组，标记元素是否已经被访问过
            DynamicArray<bool> visited(vCount());

            //初始化标记数组值全为false
            for(int j = 0; j < visited.length(); j++)
            {
                visited[j] = false;
            }


            //将图中的第一个元素压入栈中
            s.push(i);
            while(s.size() > 0)
            {
                //取出栈顶元素
                int v = s.top();
                s.pop();

                if(!visited[v])
                {
                   //获取域与栈顶元素邻接的元素
                   SharedPointer< Array<int> > aj = getAdjacent(v);
                   for(int j = aj->length() - 1; j >= 0; j--)
                   {
                       //分别将它们压入栈中
                       s.push((*aj)[j]);
                   }
                   //将弹出的栈顶元素压入输出值队列
                   r.add(v);
                   //标记当前栈顶元素已被使用过
                   visited[v] = true;
                }
            }
            //将队列转化为数组以便输出
            ret = toArray(r);
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Index i is invalid...");
        }

        return ret;
    }
};






}

#endif // GRAPH_H
