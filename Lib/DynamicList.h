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
    //��̬�����˳��洢�ռ�Ĵ�С
    int m_capacity;

public:
    //��ʼ������ĳ�Ա��ָ�����ද̬����Ŀռ�
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

    //���ض�̬����ռ�Ĵ�С
    int capacity() const
    {
        return m_capacity;
    }

    //��������˳��洢�ռ�Ĵ�С
    void resize(int capacity)
    {
        //ֻ���µĿռ��С��ԭ�ռ��С��һ��ʱ�Ž��в���
        if(capacity != m_capacity)
        {
            //��̬����ռ䣬��֤�Ժ�Ĳ��������дԭ���Ŀռ�
            T* array = new T[capacity];

            if(array != NULL)
            {

                //�Ƚ�ԭ�ռ��С���ȿռ��СȡСֵ
                int length = (this->m_length < capacity ? this->m_length : capacity);

                for(int i = 0; i < length; i++)
                {
                    //������Ԫ�ظ��Ƶ�������Ŀռ�
                    array[i] = this->m_array[i];
                }

                //��֤���Ա����ĺϷ�����
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

    //�黹�ռ�
    ~DynamicList()
    {
        delete[] this->m_array;
    }
};

}

#endif // DYNAMICLIST_H
