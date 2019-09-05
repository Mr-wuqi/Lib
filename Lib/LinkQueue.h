#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include "Exception.h"
#include "LinuxList.h"
#include "Queue.h"

namespace Lib
{
template<typename T>
class LinkQueue : public Queue<T>
{
protected:
    struct Node : public Object
    {
        list_head head;
        T value;
    };

    list_head m_header;
    int m_length;

public:
    //O(1)
    LinkQueue()
    {
        m_length = 0;

        INIT_LIST_HEAD(&m_header);
    }

    //O(1)
    void add(const T& e)
    {
        Node* node = new Node();

        if(node != NULL)
        {
            node->value = e;

            list_add_tail(&node->head, &m_header);

            m_length++;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "No memory  to add new element...");
        }
    }

    //O(1)
    void remove()
    {
        if(m_length > 0)
        {
            list_head* toDel = m_header.next;

            list_del(toDel);

            m_length--;

            delete  list_entry(toDel, Node, head);
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
            return  list_entry(m_header.next, Node, head)->value;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "No element int current queue...");
        }
    }

    //O(n)
    void clear()
    {
        while (m_length > 0) {
            remove();
        }
    }


    //O(1)
    int length() const
    {
        return m_length;
    }

    ~LinkQueue()
    {
        clear();
    }

};


}


#endif // LINKQUEUE_H
