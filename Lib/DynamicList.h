#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H
#include "SeqList.h"
#include "Exception.h"

namespace Lib
{

template <typename T>
class DynamicList : public SeqList<T>
{

protected:
    //动态申请的顺序存储空间的大小
    int m_capacity;

public:
    //初始化父类的成员和指定本类动态申请的空间
    DynamicList(int capacity)
    {
        this->m_array = new T[capacity];

        if(this->m_array != NULL)
        {
            this->m_length = 0;
            this->m_capacity = capacity;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicList object...");
        }
    }

    //返回动态申请空间的大小
    int capacity() const
    {
        return m_capacity;
    }

    //重新设置顺序存储空间的大小
    void resize(int capacity)
    {
        //只有新的空间大小和原空间大小不一样时才进行操作
        if(capacity != m_capacity)
        {
            //动态申请空间，保证以后的操作不会改写原来的空间
            T* array = new T[capacity];

            if(array != NULL)
            {

                //比较原空间大小和先空间大小取小值
                int length = (this->m_length < capacity ? this->m_length : capacity);

                for(int i = 0; i < length; i++)
                {
                    //将数组元素复制到新申请的空间
                    array[i] = this->m_array[i];
                }

                //保证线性表对象的合法可用
                T* temp = this->m_array;

                this->m_array = array;
                this->m_length = length;
                this->m_capacity = capacity;

                delete[] temp;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicList object...");
            }
        }
    }

    //归还空间
    ~DynamicList()
    {
        delete[] this->m_array;
    }
};

}

#endif // DYNAMICLIST_H
