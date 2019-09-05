#ifndef STATICLIST_H
#define STATICLIST_H
#include "SeqList.h"

namespace Lib
{

template <typename T, int N>
class StaticList : public SeqList<T>
{
protected:
    //原生数组的的大小， 指定大小为N
    T m_space[N];

public:
    //构造函数初始化父类的具体值， m_array, m_length
    StaticList()
    {
        this->m_array = m_space;
        this->m_length = 0;
    }

    //返回原生数组的大小
    int capacity() const
    {
        return N;
    }
};

}


#endif // STATICLIST_H
