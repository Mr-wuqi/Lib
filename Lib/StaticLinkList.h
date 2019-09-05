#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H
#include "LinkList.h"

namespace Lib
{

template <typename T, int N>
class StaticLinkList : public LinkList<T>
{

protected:
    //����ʹ��typename���ñ�������ΪNode����һ����Ա����������ȷ�ĸ��߱����������һ������
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
    //�������
    int m_used[N];

    SNode* create()
    {
        SNode* ret = NULL;

        for(int i = 0; i < N; i++)
        {
            if(!m_used[i])
            {

                //Ϊret�����ڴ�
                ret = reinterpret_cast<SNode*>(m_space) + i;

                //�ڷ�����ڴ��ϵ��ù��캯��
                ret = new(ret)SNode();

                //ռ�õ�ǰ�ռ�
                m_used[i] = 1;
                break;
            }
        }

        return ret;
    }

    void destroy(Node *pn)
    {
        //ǿ������ת��Ϊ����һƬ�ռ����ָ��������׼��
        SNode* space = reinterpret_cast<SNode*>(m_space);

        SNode* psn = dynamic_cast<SNode*>(pn);

        for(int i = 0; i < N; i++)
        {
            //��psnָ��ǰ��Ƭ�ڴ�ռ���i��λ��ʱ�͹黹�ռ�
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
