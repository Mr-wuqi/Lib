#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H
#include "Exception.h"
#include "Graph.h"
#include "SharedPointer.h"
#include "DynamicArray.h"

namespace Lib
{
template <int N, typename V, typename E>
class MatrixGraph : public Graph<V, E>
{

protected:
    //指针数组，每个成员都是一个指针，指向与顶点相关联的数据元素
    V* m_vertexes[N];

    E* m_edges[N][N];

    //记录当前图中有多少条边
    int m_eCount;

public:
    MatrixGraph()
    {
        for(int i = 0; i < vCount(); i++)
        {
            m_vertexes[i] = NULL;
            for(int j = 0; j < vCount(); j++)
            {
                m_edges[i][j] = NULL;
            }
        }

        m_eCount = 0;
    }

    V getVertex(int i)
    {
        V ret;

        if(!getVertex(i, ret))
        {
            THROW_EXCEPTION(InvalidParameterException, "Index i is invalid...");
        }

        return ret;
    }

    //获取当前顶点的值
    bool getVertex(int i, V& value)
    {
        bool ret = ((0 <= i) && (i < vCount()));

        if(ret)
        {
            //判断当前的顶点是否有与子关联的数据元素
            if(m_vertexes[i] != NULL)
            {
                value = *(m_vertexes[i]);
            }
            else
            {
                THROW_EXCEPTION(InvalidOperationException, "No value assigned to this vertex...");
            }
        }

        return ret;
    }

    //设置顶点的值
    bool setVertex(int i, const V& value)
    {
        bool ret = ((0 <= i) && (i < vCount()));

        if(ret)
        {
            //这里使用一个中间变量是为了异常安全设置的，如果从堆空间中申请抛异常时不影响图的数据结构
            V* data = m_vertexes[i];

            if(data == NULL)
            {
                data = new V();
            }

            if(data != NULL)
            {
                *data = value;

                m_vertexes[i] = data;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to store new vertx value...");
            }

        }

        return ret;
    }

    //求出邻接顶点
    SharedPointer< Array<int> > getAdjacent(int i)
    {
        DynamicArray<int>* ret = NULL;

        if((0 <= i) && (i < vCount()))
        {
            int n = 0;

            for(int j = 0; j < vCount(); j++)
            {
                if(m_edges[i][j] != NULL)
                {
                    n++;
                }
            }

            ret = new DynamicArray<int>(n);

            if(ret != NULL)
            {
                for(int j = 0, k = 0; j < vCount(); j++)
                {
                    //记录邻接顶点的编号
                    if(m_edges[i][j] != NULL)
                    {
                        //将邻接顶点设置到数组中
                        ret->set(k++, j);
                    }
                }
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create ret object...");
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
        return (0 <= i) && (i < vCount()) && (0 <= j) && (j < vCount()) && (m_edges[i][j] != NULL);
    }

    //获取顶点i到j之间的边上的权值
    E getEdge(int i, int j)
    {
        E ret;

        if(!getEdge(i, j, ret))
        {
            THROW_EXCEPTION(InvalidParameterException, "Index <i, j, ret> is invalid...");
        }

        return ret;
    }

    //获取顶点i到j之间的边上的权值
    bool getEdge(int i, int j, E& value)
    {
        bool ret = (((0 <= i) && (i < vCount())) && ((0 <= j) && (j < vCount())));

        if(ret)
        {

            if(m_edges[i][j] != NULL)
            {
                value = *(m_edges[i][j]);
            }
            else
            {
                THROW_EXCEPTION(InvalidOperationException, "No value assigned to this edge...");
            }
        }

        return ret;
    }

    //设置边，value表示边上的权值
    bool setEdge(int i, int j, const E& value)
    {
        bool ret = (((0 <= i) && (i < vCount())) && ((0 <= j) && (j < vCount())));

        if(ret)
        {
            E* ne = m_edges[i][j];

            if(ne == NULL)
            {
                ne = new E();

                if(ne != NULL)
                {
                    *ne = value;

                    m_edges[i][j] = ne;

                    m_eCount++;
                }
                else
                {
                    THROW_EXCEPTION(NoEnoughMemoryException, "No memory to store new edge value...");
                }
            }
            else
            {
                *ne = value;
            }
        }

        return ret;
    }

    //删除一条边
    bool removeEdge(int i, int j)
    {
        bool ret = (((0 <= i) && (i < vCount())) && ((0 <= j) && (j < vCount())));

        if(ret)
        {
            E* toDel = m_edges[i][j];

            m_edges[i][j] = NULL;

            if(toDel != NULL)
            {
                m_eCount--;

                delete toDel;
            }

        }

        return ret;
    }

    int vCount()
    {
        return N;
    }

    int eCount()
    {
        return m_eCount;
    }

    //计算出度，找出当前行为非空的元素证明元素之间有连接
    int OD(int i)
    {
        int ret = 0;

        if((0 <= i) && (i < vCount()))
        {
            for(int j = 0; j < vCount(); j++)
            {
                if(m_edges[i][j] != NULL)
                {
                    ret++;
                }
            }
        }
        else
        {
           THROW_EXCEPTION(InvalidParameterException, "Index i is invalid...");
        }

        return ret;
    }

    //计算入度，计算入度，找出当前列为非空的元素证明元素之间有连接
    int ID(int i)
    {
        int ret = 0;

        if((0 <= i) && (i < vCount()))
        {
            for(int j = 0; j < vCount(); j++)
            {
                //邻接矩阵中对应的列中非零值
                if(m_edges[j][i] != NULL)
                {
                    ret++;
                }
            }
        }
        else
        {
           THROW_EXCEPTION(InvalidParameterException, "Index i is invalid...");
        }

        return ret;
    }


    ~MatrixGraph()
    {
        for(int i = 0; i < vCount(); i++)
        {
            m_vertexes[i] = NULL;
            for(int j = 0; j < vCount(); j++)
            {
                delete m_edges[i][j];
            }

            delete m_vertexes[i];
        }
    }


};

}

#endif // MATRIXGRAPH_H
