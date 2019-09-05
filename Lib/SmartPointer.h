#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
#include "Pointer.h"

namespace Lib
{

template<typename T>
class SmartPointer : public Pointer<T>
{
public:
    SmartPointer(T* p = NULL):Pointer<T>(p)
    {

    }

    //同一片堆空间只能由一个指针所指向
    SmartPointer(const SmartPointer<T>& obj)
    {
        //转移所有权
        this->m_pointer = obj.m_pointer;

        const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
    }


    SmartPointer<T>& operator = (const SmartPointer<T>& obj)
    {
        if (this != &obj)
        {
            T* p = this->m_pointer;

            this->m_pointer = obj.m_pointer;

            const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;

            delete p;
        }

        return *this;
    }

    ~SmartPointer()
    {
        delete this->m_pointer;
    }

};




}

#endif // SMARTPOINTER_H
