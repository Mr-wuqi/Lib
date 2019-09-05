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

    //��װ�Ĺ��ܺ���
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
    //��������Աָ���ÿ�
    SharedPointer(T* p = NULL) : m_ref(NULL)
    {
        if(p)
        {
            //�ڶѿռ��д���һ����������
            this->m_ref = reinterpret_cast<int*>((std::malloc(sizeof(int))));

            if(this->m_ref)
            {
                //����ָ��p�Ѿ���һ������ָ����ָ����
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
           //��ղ�������Ϊ�п��ܵ�ǰ������ָ������Ѿ�ָ����һ������
            clear();
            assign(obj);
        }

        return *this;
    }


    //�ÿյ�ǰ����ָ�����
    void clear()
    {
       T* toDel = this->m_pointer;
       int* ref = this->m_ref;

       this->m_pointer = NULL;
       this->m_ref = NULL;

       //����������һ
       if(ref)
       {
           (*ref)--;

           if(*ref == 0)
           {
               //�ͷż�������
               free(ref);

               //�ͷŶѿռ�
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
