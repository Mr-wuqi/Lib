#ifndef SEQLIST_H
#define SEQLIST_H
#include "Exception.h"
#include "List.h"

namespace Lib
{

template <typename T>
class SeqList : public List<T>
{
protected:
    T* m_array;         //顺序表的顺序存储空间
    int m_length;       //当前线性表的长度

public:
    //尾插法
    bool insert(const T& e)                 //O(1)
    {
        return insert(m_length, e);
    }

    bool insert(int i, const T& e)          //O(n)
    {
        bool ret = (0 <= i && i <= m_length);

        ret = (ret && (m_length + 1) <= capacity());

        if(ret)
        {
            for(int p = m_length - 1; p >= i; p--)
            {
                m_array[p + 1] = m_array[p];
            }

            m_array[i] = e;

            m_length++;
        }

        return ret;
    }

    bool remove(int i)                      //O(n)
    {
        bool ret = (0 <= i && i < m_length);

        if(ret)
        {
            for(int p = i; p < m_length - 1; p++)
            {
                m_array[p] = m_array[p + 1];
            }

            m_length--;
        }

        return ret;
    }

    bool set(int i, const T& e)
    {
        bool ret = (0 <= i && i < m_length);

        if (ret)
        {
            m_array[i] = e;
        }

        return ret;
    }

    bool get(int i, T& e) const
    {
        bool ret = (0 <= i && i < m_length);

        if (ret)
        {
            e = m_array[i];
        }

        return ret;
    }

    //查找元素
    int find(const T& e) const      //O(n)
    {
        int ret = -1;

        for(int i = 0; i < m_length; i++)
        {
            if(m_array[i] == e)
            {
                ret = i;
                break;
            }
        }

        return ret;
    }

    //线性表的长度
    int length() const
    {
        return m_length;
    }

    void clear()
    {
        m_length = 0;
    }

    //顺序存储线性表的数组访问方式
    T& operator [] (int i)
    {
        if(0 <= i && i < m_length)
        {
            return m_array[i];
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Parameter is Invalid...");
        }
    }

    //代码复用,先剔除const对象的const属性再调用非const的方法
    T operator [](int i) const
    {
        return (const_cast<SeqList<T>&>(*this))[i];
    }

    //顺序存储空间的容量即映射数组的大小
    virtual int capacity() const = 0;
};


}

#endif // SQLIST_H
