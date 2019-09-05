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
    //ָ�����飬ÿ����Ա����һ��ָ�룬ָ���붥�������������Ԫ��
    V* m_vertexes[N];

    E* m_edges[N][N];

    //��¼��ǰͼ���ж�������
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

    //��ȡ��ǰ�����ֵ
    bool getVertex(int i, V& value)
    {
        bool ret = ((0 <= i) && (i < vCount()));

        if(ret)
        {
            //�жϵ�ǰ�Ķ����Ƿ������ӹ���������Ԫ��
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

    //���ö����ֵ
    bool setVertex(int i, const V& value)
    {
        bool ret = ((0 <= i) && (i < vCount()));

        if(ret)
        {
            //����ʹ��һ���м������Ϊ���쳣��ȫ���õģ�����Ӷѿռ����������쳣ʱ��Ӱ��ͼ�����ݽṹ
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

    //����ڽӶ���
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
                    //��¼�ڽӶ���ı��
                    if(m_edges[i][j] != NULL)
                    {
                        //���ڽӶ������õ�������
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

    //��ȡ����i��j֮��ı��ϵ�Ȩֵ
    E getEdge(int i, int j)
    {
        E ret;

        if(!getEdge(i, j, ret))
        {
            THROW_EXCEPTION(InvalidParameterException, "Index <i, j, ret> is invalid...");
        }

        return ret;
    }

    //��ȡ����i��j֮��ı��ϵ�Ȩֵ
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

    //���ñߣ�value��ʾ���ϵ�Ȩֵ
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

    //ɾ��һ����
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

    //������ȣ��ҳ���ǰ��Ϊ�ǿյ�Ԫ��֤��Ԫ��֮��������
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

    //������ȣ�������ȣ��ҳ���ǰ��Ϊ�ǿյ�Ԫ��֤��Ԫ��֮��������
    int ID(int i)
    {
        int ret = 0;

        if((0 <= i) && (i < vCount()))
        {
            for(int j = 0; j < vCount(); j++)
            {
                //�ڽӾ����ж�Ӧ�����з���ֵ
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
