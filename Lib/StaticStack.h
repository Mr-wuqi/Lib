#ifndef STATICSTACK_H
#define STATICSTACK_H
#include "Exception.h"
#include "Stack.h"

namespace Lib
{
template <typename T, int N>
class StaticStack : public Stack<T>
{
protected:
    //ջ�洢�ռ䣬Nλģ�����
    T m_space[N];
    //ջ����ʶ
    int m_top;
    //��ǰջ�Ĵ�С
    int m_size;

public:
    StaticStack()   //O(1)
    {
        m_top = -1;
        m_size = 0;
    }

    void push(const T& e)   //O(1)
    {
        if(m_size < N)
        {
            //Ϊ�˱�����ܷ����쳣������ջ�ṹ�仯Ӧ���ȸ�ֵ��ջ����ʶ�ټ�һ
            m_space[m_top + 1] = e;
            m_top++;
            m_size++;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "No space in current stack...");
        }
    }

    void pop()      //O(1)
    {
        if(m_size > 0)
        {
            m_top--;
            m_size--;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "No element in current stack...");
        }
    }

    T top() const   //O(1)
    {
        if(m_size > 0)
        {
            return  m_space[m_top];
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "No element in current stack...");
        }
    }

    //˳��ջʵ��
    void clear()    //O(1)
    {
        m_top = -1;
        m_size = 0;
    }

    int size() const    //O(1)
    {
        return  m_size;
    }

    int capacity() const    //O(1)
    {
        return  N;
    }

};


}


#endif // STATICSTACK_H
