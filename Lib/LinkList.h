#ifndef LINKLIST_H
#define LINKLIST_H
#include "List.h"
#include "Exception.h"

namespace Lib
{

template <typename T>
class LinkList : public List<T>
{
protected:
    //���ݽ��
    struct Node : public Object
    {
        T value;
        Node* next;
    };

    //ͷ���
    mutable struct : public Object
    {
        char reserved[sizeof(T)];
        Node* next;
    }m_header;

    //��������
    int m_length;

    //�����α�ÿ���ƶ��Ľ�����Ŀ
    int m_step;
    //�α�     move,next,current,end����һ��ʹ����߱���Ч�ʣ�˼��:����һ�����һ��
    Node* m_current;


    //O(n)
    Node* position(int i) const
    {
        Node* ret = reinterpret_cast<Node*>(&m_header);

        for(int p = 0; p < i; p++)
        {
            ret = ret->next;
        }

        return ret;
    }

    //��װ���������ɾ����������������ǿ��չ��
    //�ڶѿռ��ڲ�����Node����
    virtual Node* create()
    {
        return new Node();
    }

    //�ͷŶѿռ��е�node����
    virtual void destroy(Node* pn)
    {
        delete pn;
    }


public:
    LinkList()
    {
        m_header.next = NULL;
        m_length = 0;
        m_step = 1;
        m_current = NULL;
    }


    //O(n)
    bool insert(int i, const T& e)
    {

        bool ret = ((0 <= i) && (i <= m_length));

        if(ret)
        {
            Node* node = create();

            if(node != NULL)
            {
                Node* current = position(i);

                node->value = e;
                node->next = current->next;
                current->next = node;

                m_length++;

            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No enough memory to insert element...");
            }
        }

        return ret;
    }

    //β�巨
    bool insert(const T& e)
    {
        return insert(m_length, e);
    }


    //O(n)
    bool remove(int i)
    {
        bool ret = ((0 <= i) && (i < m_length));

        if(ret)
        {
            Node* current = position(i);

            Node* toDel = current->next;

            if(m_current == toDel)
            {
                m_current = toDel->next;
            }

            current->next = toDel->next;

            m_length--;

            destroy(toDel);
        }

        return ret;
    }

    //O(n)
    bool set(int i, const T& e)
    {
        bool ret = ((0 <= i) && (i < m_length));

        if(ret)
        {

            position(i)->next->value = e;
        }

        return ret;
    }

    //Ϊ�˱��ڴ�ӡ���������һ��get����
    //O(n)
    virtual T get(int i) const
    {
        T ret;

        if(get(i, ret))
        {
            return ret;
        }
        else
        {
            THROW_EXCEPTION(IndexOutBoundsException, "Invalid Parameter i is to get element...");
        }

        return ret;
    }

    bool get(int i, T& e) const
    {
        bool ret = ((0 <= i) && (i < m_length));

        if(ret)
        {
            e = position(i)->next->value;
        }

        return ret;
    }

    //O(n)
    int find(const T& e) const
    {
        int ret = -1;
        int i = 0;

        Node* node = m_header.next;

        while( node )
        {
            if(node->value == e)
            {
                ret = i;
                break;
            }
            else
            {
                node = node->next;
                i++;
            }
        }

        return ret;
    }

    //O(1)
    int length() const
    {
        return m_length;
    }

    //O(n)
    void clear()
    {
        while(m_header.next)
        {
            Node* toDel = m_header.next;

            m_header.next = toDel->next;

            m_length--;

            destroy(toDel);
        }
    }

    //���α궨λ��Ŀ��λ��i��λ�ã����ҿ�����step��������һ���ƶ��Ľڵ�ĸ���
    virtual bool move(int i, int step = 1)
    {
        bool ret = ((0 <= i) && (i < m_length) && (step > 0));

        if(ret)
        {
            //��λ��Ŀ��λ�ô��Ľڵ�
            m_current = position(i)->next;
            //�α�ÿ���ƶ��Ľڵ���
            m_step = step;
        }

        return ret;
    }

    virtual bool end()
    {
        return (m_current == NULL);
    }

    //���ص�ǰ�α���ָ��ĵ�ǰ����Ԫ�ص�ֵ
    virtual T current()
    {
        if(!end())
        {
            return m_current->value;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "No value at current position...");
        }
    }

    //�α����
    virtual bool next()
    {
        int i = 0;

        while((i < m_step) && !end())
        {
            m_current = m_current->next;
            i++;
        }

        //�ƶ��Ľڵ����͵�ǰm_step��ֵ�Ƿ���ȵ�
        return (i == m_step);
    }

    //O(n)
    ~LinkList()
    {
        clear();
    }

};

}

#endif // LINKLIST_H
