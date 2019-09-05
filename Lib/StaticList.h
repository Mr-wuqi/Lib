#ifndef STATICLIST_H
#define STATICLIST_H
#include "SeqList.h"

namespace Lib
{

template <typename T, int N>
class StaticList : public SeqList<T>
{
protected:
    //ԭ������ĵĴ�С�� ָ����СΪN
    T m_space[N];

public:
    //���캯����ʼ������ľ���ֵ�� m_array, m_length
    StaticList()
    {
        this->m_array = m_space;
        this->m_length = 0;
    }

    //����ԭ������Ĵ�С
    int capacity() const
    {
        return N;
    }
};

}


#endif // STATICLIST_H
