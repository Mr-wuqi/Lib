#ifndef LISTGRAPH_H
#define LISTGRAPH_H

#include "Graph.h"
#include "LinkList.h"
#include "Exception.h"
#include "DynamicArray.h"


namespace Lib
{
template <typename V, typename E>
class ListGraph : public Graph<V, E>
{
protected:
    struct Vertex : public Object
    {
        V* data;
        LinkList< Edge<E> > edge;

        Vertex()
        {
            data = NULL;
        }
    };

    //邻接链表
    LinkList<Vertex*> m_list;
public:
    //创建顶点数
    ListGraph(unsigned int n = 0)
    {
        for(unsigned int i = 0; i < n; i++)
        {
            addVertex();
        }
    }

    int addVertex()     //O(n)
    {
        int ret = -1;
        //从堆空间中创建一个顶点对象出来
        Vertex* v = new Vertex();

        if(v != NULL)
        {
            m_list.insert(v);

            //返回新的顶点在链表里的编号
            ret = m_list.length() - 1;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create new vertex object...");
        }

        return ret;
    }

    //增加一个顶点同时设置相应得值
    int addVertex(const V& value)   //O(n)
    {
        //增加新的顶点
        int ret = addVertex();

        //设置值
        if(ret >= 0)
        {
            setVertex(ret, value);
        }

        return ret;
    }

    //设置顶点元素相关得值
    bool setVertex(int i, const V& value)   //O(n)
    {
        bool ret = ((0 <= i) && (i < vCount()));

        if(ret)
        {
            //将顶点中相关得元素取出来
            Vertex* vertex = m_list.get(i);
            V* data = vertex->data;

            if(data == NULL)
            {
                data = new V();
            }

            if(data != NULL)
            {
                *data = value;

                vertex->data = data;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create new vertex object...");
            }
        }

        return ret;
    }

    V getVertex(int i)  //O(n)
    {
        V ret;

        if(!getVertex(i, ret))
        {
            THROW_EXCEPTION(InvalidParameterException, "Index i is innvalid...");
        }

        return ret;
    }

    bool getVertex(int i, V&  value)    //O(n)
    {
        bool ret = ((0 <= i) && (i < vCount()));

        if(ret)
        {
            //将与顶点相关得数据元素取出来
            Vertex* v = m_list.get(i);

            if(v->data != NULL)
            {
                value = *(v->data);
            }
            else
            {
                THROW_EXCEPTION(InvalidOperationException, "No value assigned to this vertex...");
            }
        }

        return ret;
    }

    //删除最近添加得节点而不是以前存在得顶点，为了保证原图得大体完整性
    void removeVertex()     //O(n*n)
    {
        //判断当前图中是否有顶点
        if(m_list.length() > 0)
        {
            //找到最近添加得顶点下标
            int index = m_list.length() - 1;

            Vertex* v = m_list.get(index);

            if(m_list.remove(index))
            {
                for(int i = (m_list.move(0), 0); !m_list.end(); i++, m_list.next())
                {
                    //查找以i作为起点index作为终点得边是否在邻接链表中存在得话pos大于等于0
                    int pos = m_list.current()->edge.find(Edge<E>(i, index));

                    if(pos >= 0)
                    {
                        //在当前顶点得邻接链表中删除此边
                        m_list.current()->edge.remove(pos);
                    }
                }

                delete v->data;
                delete v;
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "No vertex in current graph...");
        }
    }

    //获取从顶点i可以抵达得其他顶点得编号
    SharedPointer< Array<int> > getAdjacent(int i)  //O(n)
    {
        DynamicArray<int>* ret = NULL;

        if((0 <= i) && (i < vCount()))
        {
            Vertex* vertex = m_list.get(i);

            //将返回值数组创建出来
            ret = new DynamicArray<int>(vertex->edge.length());

            if(ret != NULL)
            {
                for(int k = (vertex->edge.move(0), 0); !vertex->edge.end(); k++,vertex->edge.next())
                {
                    ret->set(k, vertex->edge.current().e);
                }
            }
            else
            {
                THROW_EXCEPTION(InvalidParameterException, "No memory to create ret object...");
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Index i is invalid...");
        }

        return ret;
    }

    bool isAdjacent(int i, int j)
    {
        return (0 <= i) && (i < vCount()) && (0 <= j) && (j < vCount()) && (m_list.get(i)->edge.find(Edge<E>(i, j)) >= 0);
    }

    E getEdge(int i, int j)
    {
        E ret;

        if(!getEdge(i, j, ret))
        {
            THROW_EXCEPTION(InvalidParameterException, "Edge <i, j> is invalid...");
        }

        return ret;
    }

    bool getEdge(int i, int j, E& value)    //O(n)
    {
        bool ret = (((0 <= i) && (i < vCount())) && ((0 <= j) && (j < vCount())));

        if(ret)
        {
            Vertex* vertex = m_list.get(i);
            int pos = vertex->edge.find(Edge<E>(i, j));

            if(pos >= 0)
            {
                value = vertex->edge.get(pos).data;
            }
            else
            {
                THROW_EXCEPTION(InvalidOperationException, "No value assigned to this edge...");
            }
        }

        return ret;
    }

    bool setEdge(int i, int j, const E& value)      //O(n)
    {
        bool ret = ((0 <= i) && (i < vCount()) && (0 <= j) && (j < vCount()));

        if(ret)
        {
            Vertex* vertex = m_list.get(i);
            int pos = vertex->edge.find(Edge<E>(i, j));

            if(pos >= 0)
            {
                ret = vertex->edge.set(pos, Edge<E>(i, j, value));
            }
            else
            {
                ret = vertex->edge.insert(0, Edge<E>(i, j, value));
            }
        }

        return ret;
    }

    bool removeEdge(int i, int j)   //O(n)
    {
        bool ret = (((0 <= i) && (i < vCount())) && ((0 <= j) && (j < vCount())));

        if(ret)
        {
            Vertex* vertex = m_list.get(i);
            int pos = vertex->edge.find(Edge<E>(i, j));

            if(pos >= 0)
            {
                ret = vertex->edge.remove(pos);
            }
        }

        return ret;
    }

    //获取当前图中顶点的数目
    int vCount()    //O(1)
    {
        return m_list.length();
    }

    int eCount()    //O(n)
    {
        int ret = 0;

        for(m_list.move(0); !m_list.end(); m_list.next())
        {
            ret += m_list.current()->edge.length();
        }

        return ret;
    }

    int ID(int i)   //O(n * n)
    {
        int ret = 0;

        if((0 <= i) && (i < vCount()))
        {
            for(m_list.move(0); !m_list.end(); m_list.next())
            {
                LinkList< Edge<E> >& edge = m_list.current()->edge;

                for(edge.move(0); !edge.end(); edge.next())
                {
                    //统计一下有多少条边的终止顶点为i
                    if(edge.current().e == i)
                    {
                        ret++;
                        break;
                    }
                }
            }
        }
        else
        {
             THROW_EXCEPTION(InvalidParameterException, "Index i is invalid...");
        }

        return ret;
    }

    int OD(int i)   //O(n)
    {
        int ret = 0;

        if((0 <= i) && (i < vCount()))
        {
            ret = m_list.get(i)->edge.length();
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Index i is invalid...");
        }

        return ret;
    }

    ~ListGraph()
    {
        while(m_list.length() > 0)
        {
            Vertex* toDel = m_list.get(0);

            m_list.remove(0);

            delete toDel->data;
            delete toDel;
        }
    }

};


}

#endif // LISTGRAPH_H
