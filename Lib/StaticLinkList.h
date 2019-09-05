#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H
#include "LinkList.h"

namespace Lib
{

template <typename T, int N>
class StaticLinkList : public LinkList<T>
{

protected:
    //这里使用typename是让编译器认为Node不是一个成员函数而是明确的告诉编译器其后是一个类型
    typedef typename LinkList<T>::Node Node;

    struct SNode : public Node
    {
        void* operator new(unsigned int size, void* loc)
        {
            (void)size;
            return loc;
        }
    };

    unsigned char m_space[sizeof(SNode) * N];
    //标记数组
    int m_used[N];

    SNode* create()
    {
        SNode* ret = NULL;

        for(int i = 0; i < N; i++)
        {
            if(!m_used[i])
            {

                //为ret分配内存
                ret = reinterpret_cast<SNode*>(m_space) + i;

                //在分配的内存上调用构造函数
                ret = new(ret)SNode();

                //占用当前空间
                m_used[i] = 1;
                break;
            }
        }

        return ret;
    }

    void destroy(Node *pn)
    {
        //强制类型转换为对这一片空间进行指针运算做准备
        SNode* space = reinterpret_cast<SNode*>(m_space);

        SNode* psn = dynamic_cast<SNode*>(pn);

        for(int i = 0; i < N; i++)
        {
            //当psn指向当前这片内存空间中i的位置时就归还空间
            if(psn == (space))
            {
                m_used[i] = 0;
                psn->~SNode();
                break;
            }
        }

    }

public:
    StaticLinkList()
    {
        for(int i = 0; i < N; i++)
        {
            m_used[i] = 0;
        }
    }

    ~StaticLinkList()
    {
        this->clear();
    }

};


}




#endif // STATICLINKLIST_H
