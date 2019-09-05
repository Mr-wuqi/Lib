#ifndef STATICQUEUE_H
#define STATICQUEUE_H
#include "Queue.h"
#include "Exception.h"

namespace Lib
{

template<typename T, int N>
class StaticQueue : public Queue<T>
{

protected:
    //队列存储空间，N位模板参数
    T m_space[N];
    //队头标识
    int m_front;
    //队尾标识
    int m_rear;
    int m_length;

public:
    StaticQueue()
    {
        m_front = 0;
        m_rear = 0;
        m_length = 0;
    }

    //进队列操作     O(1)
    void add(const T& e)
    {
        if(m_length < N)
        {
            m_space[m_rear] = e;
            m_rear = (m_rear + 1) % N;
            m_length++;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "No space int current queue...");
        }
    }

    //O(1)
    void remove()
    {
        if(m_length > 0)
        {
            m_front = (m_front + 1) % N;
            m_length--;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "No element int current queue...");
        }
    }

    //O(1)
    T front() const
    {
        if(m_length > 0)
        {
            return  m_space[m_front];
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "No element int current queue...");
        }
    }

    //O(1)
    void clear()
    {
        m_front = 0;
        m_rear = 0;
        m_length = 0;
    }

    //O(1)
    int length() const
    {
        return m_length;
    }

    //O(1)
    int capacity() const
    {
        return N;
    }

};

}

#endif // STATICQUEUE_H
