#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include "Array.h"
#include "Exception.h"

namespace Lib
{

template <typename T>
class DynamicArray : public Array<T>
{
protected:
    int m_length;


    //拷贝功能函数解决代码冗余问题    O(min(len. newLen)) ==> O(n)
    T* copy(T* array, int len, int newLen)
    {
        T* ret = new T[newLen];

        if(ret != NULL)
        {
            int size = (len < newLen ? len : newLen);

            for(int i = 0; i < size; i++)
            {
                ret[i] = array[i];
            }
        }
        return ret;
    }

    //设置当前成员变量的值，m_array m_length   O(1)
    void update(T* array, int length)
    {
        if(array != NULL)
        {
            T* temp = this->m_array;

            this->m_array = array;
            this->m_length = length;

            delete [] temp;
        }
        else
        {
           THROW_EXCEPTION(NoEnoughMemoryException, "No memory to update Dynamic Array...");
        }
    }

    //消除构造函数冗余得功能函数     O(1)
    void init(T* array, int length)
    {
        if(array != NULL)
        {
            this->m_array = array;
            this->m_length = length;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to init Dynamic Array...");
        }
    }


public:
    DynamicArray(int length = 0)    //O(1)
    {
        //功能函数消除构造函数冗余

        init(new T[length], length);

        ////////////////////////////////////////////////////////////
        /*this->m_array = new T[length];

        if(this->m_array != NULL)
        {
            this->m_length = length;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create Dynamic Array...");
        }*/
    }

    DynamicArray(const DynamicArray<T>& obj)    //O(n)
    {

        //调用init功能函数消除代码1冗余

        init(copy(obj.m_array, obj.m_length, obj.m_length), obj.m_length);
        ////////////////////////////////////////////////
        /*this->m_array = new T[obj.m_length];

        if(this->m_array != NULL)
        {
            this->m_length = obj.m_length;

            for(int i = 0; i < obj.m_length; i++)
            {
                this->m_array[i] = obj.m_array[i];
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create Dynamic Array...");
        }*/

    }

    DynamicArray<T>& operator = (const DynamicArray<T>& obj)    //O(n)
    {
        if(this != &obj)
        {

            //利用功能函数消除下方代码冗余实现，贼拉风

            update(copy(obj.m_array, obj.m_length, obj.m_length), obj.m_length);
            /////////////////////////////////////////////////
            //此处与DynamicList的思想相同
            /*T* array = new T[obj.m_length];

            if(array != NULL)
            {

                for(int i = 0; i < obj.m_length; i++)
                {
                    array[i] = obj.m_array[i];
                }

                T* temp = this->m_array;

                this->m_array = array;
                this->m_length = obj.m_length;

                delete [] temp;

            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to copy Dynamic Array...");
            }*/
        }

        return *this;
    }

    int length() const
    {
        return m_length;
    }

    void resize(int length)     //O(n)
    {
        if(length != m_length)
        {

            //利用功能函数消除下方代码冗余实现，贼拉风

            update(copy(this->m_array, m_length, length), length);

            ////////////////////////////////////////////////////////
            /*T array = new T[length];

            if(array != NULL)
            {
                int size = (m_length < length ? m_length : length);

                for(int i = 0; i < size; i++)
                {
                    array[i] = this->m_array[i];
                }

                T* temp = this->m_array;

                this->m_array = array;
                this->m_length = length;

                delete [] temp;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to resize Dynamic Array...");
            }*/
        }
    }

    ~DynamicArray()     //O(1)
    {
        delete [] this->m_array;
    }
};


}

#endif // DYNAMICARRAY_H
