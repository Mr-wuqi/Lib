#ifndef CIRCLELIST_H
#define CIRCLELIST_H
#include "LinkList.h"

namespace Lib
{

template <typename T>
class CircleList : public LinkList<T>
{
protected:
    typedef typename LinkList<T>::Node Node;

    //取余操作
    int mod(int i) const
    {
        return (this->m_length == 0) ? 0 : (i % this->m_length);
    }

    //返回尾结点
    Node* last() const
    {
        return this->position(this->m_length - 1)->next;
    }
    //链表首尾相连
    void last_to_first() const
    {
        last()->next = this->m_header.next;
    }

public:
    bool insert(const T& e)
    {
        return insert(this->m_length, e);
    }

    bool insert(int i, const T& e)
    {
        bool ret = true;

        //为什么m_length + 1 ? 归一化i？
        i = i % (this->m_length + 1);

        ret = LinkList<T>::insert(i, e);

        if(ret && (i == 0))
        {
            last_to_first();
        }

        return ret;
    }

    bool remove(int i)
    {
        bool ret = true;

        i = mod(i);

        if(i == 0)
        {
            Node* toDel = this->m_header.next;

            if(toDel != NULL)
            {
                this->m_header.next = toDel->next;
                this->m_length--;
            }

            //判断循环链表中元素是否为空
            if(this->m_length > 0)
            {
                last_to_first();

                if(this->m_current == toDel)
                {
                    this->m_current = toDel->next;
                }

            }
            else
            {
                this->m_header.next = NULL;
                this->m_current = NULL;
            }

            this->destroy(toDel);
        }
        //删除非首结点的情形
        else
        {
            ret = LinkList<T>::remove(i);
        }

        return ret;
    }

    bool set(int i, const T& e)
    {
        return LinkList<T>::set(mod(i), e);
    }

    T get(int i) const
    {
        return LinkList<T>::get(mod(i));
    }

    bool get(int i, const T& e) const
    {
        return LinkList<T>::get(mod(i), e);
    }

    int find(const T& e) const
    {
        int ret = -1;

        Node* slider = this->m_header.next;

        for(int i = 0; i < this->m_length; i++)
        {
            if(slider->value == e)
            {
                ret=  i;
                break;
            }

            slider = slider->next;
        }

        return ret;
    }

    void clear()        //O(n)
    {
        while(this->m_length > 1)   //O(n)
        {
            //提高效率所以是1
            remove(1);      //O(1)
        }

        if(this->m_length == 1)     //O(n)
        {
            Node* toDel = this->m_header.next;

            this->m_header.next = NULL;
            this->m_length = 0;
            this->m_current = NULL;

            this->destroy(toDel);
        }
    }

    bool move(int i, int step)      //O(n)
    {
        return LinkList<T>::move(mod(i),step);
    }

    bool end()      //O(1)
    {
        return (this->m_length == 0) || (this->m_current == NULL);
    }

    ~CircleList()   //O(n)
    {
        clear();
    }

};

}

#endif // CIRCLELIST_H
