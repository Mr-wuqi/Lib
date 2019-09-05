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
    //栈存储空间，N位模板参数
    T m_space[N];
    //栈顶标识
    int m_top;
    //当前栈的大小
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
            //为了避免可能发生异常，导致栈结构变化应该先赋值，栈顶标识再加一
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

    //顺序栈实现
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
