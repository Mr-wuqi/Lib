#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H
#include <cstdlib>
#include "Pointer.h"
#include "Exception.h"

namespace Lib
{

template <typename T>
class SharedPointer : public Pointer<T>
{

protected:
    int* m_ref;

    //封装的功能函数
    void assign(const SharedPointer<T>& obj)
    {
        this->m_pointer = obj.m_pointer;
        this->m_ref = obj.m_ref;

        if(this->m_ref)
        {
            *(this->m_ref)++;
        }
    }
public:
    //将计数成员指针置空
    SharedPointer(T* p = NULL) : m_ref(NULL)
    {
        if(p)
        {
            //在堆空间中创建一个计数变量
            this->m_ref = reinterpret_cast<int*>((std::malloc(sizeof(int))));

            if(this->m_ref)
            {
                //参数指针p已经有一个智能指针所指向了
                *(this->m_ref) = 1;
                this->m_pointer = p;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create SharePointer object...");
            }
        }
    }

    SharedPointer(const SharedPointer<T>& obj) : Pointer<T>(NULL)
    {
        assign(obj);
    }

    SharedPointer<T>& operator = (const SharedPointer<T>& obj)
    {
        if(this != &obj)
        {
           //清空操作，因为有可能当前的智能指针对象已经指向了一个对象
            clear();
            assign(obj);
        }

        return *this;
    }


    //置空当前智能指针对象
    void clear()
    {
       T* toDel = this->m_pointer;
       int* ref = this->m_ref;

       this->m_pointer = NULL;
       this->m_ref = NULL;

       //计数变量减一
       if(ref)
       {
           (*ref)--;

           if(*ref == 0)
           {
               //释放计数变量
               free(ref);

               //释放堆空间
               delete toDel;
           }
       }

    }

    ~SharedPointer()
    {
        clear();
    }


};

template <typename T>
bool operator == (const SharedPointer<T>& l, const SharedPointer<T>& r)
{
    return (l.get() == r.get());
}

template <typename T>
bool operator != (const SharedPointer<T>& l, const SharedPointer<T>& r)
{
    return !(l==r);
}

}

#endif // SHAREDPOINTER_H
