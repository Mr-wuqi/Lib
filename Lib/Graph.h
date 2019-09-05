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
//V�붥����ص�����Ԫ�ص����ͣ�E�����ص�����Ԫ�ص�����
template <typename V, typename E>
class Graph : public Object
{
protected:
    template <typename T>
    //������ת��Ϊ����
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

    //��С�������㷨prim
    SharedPointer < Array< Edge<E> > > prim(const E& LIMIT)
    {
        //E����
        LinkQueue< Edge<E> > ret;
        //�ж��Ƿ�������ͼ����Ϊprim�㷨ֻ����������ͼ
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
                //Ȩֵ����Ӧ�ı�
                adjVex[(*aj)[j]] = v;
            }

            //���ѭ��n�Σ�Ҳ���Ƕ������Ŀ
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

                    //��Ƕ��������T����
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


    //����Ϊ��ʼ����ı��,ͼ�Ĺ�����ȱ���
    SharedPointer< Array<int> > BFS(int i)
    {
        DynamicArray<int>* ret = NULL;

        if((0 <= i) && (i < vCount()))
        {
            LinkQueue<int> q;
            LinkQueue<int> r;
            DynamicArray<bool> visited(vCount());

            //��������ʼ��
            for(int i = 0; i < visited.length(); i++)
            {
                visited[i] = false;
            }
            //��ͼ��Ԫ��i����q������
            q.add(i);

            while(q.length() > 0)
            {
                //ȡ�ö�ͷ��ͷԪ��
                int v = q.front();

                q.remove();
                //�鿴��ͷԪ���Ƿ񱻷��ʹ������û�����ʹ������ڽӶ���ѹ�������
                if(!visited[v])
                {
                    SharedPointer< Array<int> > aj = getAdjacent(v);

                    for(int j = 0; j < aj->length(); j++)
                    {
                        q.add((*aj)[j]);
                    }

                    //��Ԫ��v���뵽r������
                    r.add(v);
                    visited[v] = true;
                }
            }
            //������ֵ����ת��Ϊ����
            ret = toArray(r);
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Index i is invalid...");
        }

        return ret;
    }

    //ͼ��������ȱ���
    SharedPointer< Array<int> > DFS(int i)
    {
        //�洢�������ֵ������
        DynamicArray<int>* ret = NULL;

        if((0 <= i) && (i < vCount()))
        {
            LinkStack<int> s;
            LinkQueue<int> r;
            //������飬���Ԫ���Ƿ��Ѿ������ʹ�
            DynamicArray<bool> visited(vCount());

            //��ʼ���������ֵȫΪfalse
            for(int j = 0; j < visited.length(); j++)
            {
                visited[j] = false;
            }


            //��ͼ�еĵ�һ��Ԫ��ѹ��ջ��
            s.push(i);
            while(s.size() > 0)
            {
                //ȡ��ջ��Ԫ��
                int v = s.top();
                s.pop();

                if(!visited[v])
                {
                   //��ȡ����ջ��Ԫ���ڽӵ�Ԫ��
                   SharedPointer< Array<int> > aj = getAdjacent(v);
                   for(int j = aj->length() - 1; j >= 0; j--)
                   {
                       //�ֱ�����ѹ��ջ��
                       s.push((*aj)[j]);
                   }
                   //��������ջ��Ԫ��ѹ�����ֵ����
                   r.add(v);
                   //��ǵ�ǰջ��Ԫ���ѱ�ʹ�ù�
                   visited[v] = true;
                }
            }
            //������ת��Ϊ�����Ա����
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
