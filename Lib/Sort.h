#ifndef SORT_H
#define SORT_H
#include "Array.h"
#include "Object.h"


namespace Lib
{

class Sort : public Object
{
private:
    Sort();
    Sort(const Sort&);
    Sort& operator = (const Sort&);

    template<typename T>
    static void Swap(T& a, T& b)
    {
        T c(a);
        a = b;
        b = c;
    }


    template<typename T>
    //将src这个数组里的元素排序，需要使用辅助数组helper，开始位置为begin结束为end
    static void Merge(T src[], T helper[], int begin, int mid, int end, bool min2max)
    {
        //左半边空间起始位置
        int i = begin;
        //右半边空间起始位子
        int j = mid + 1;
        //辅助数组起始位置
        int k = begin;

        while ((i <= mid) && (j <= end)) {
            if(min2max ? (src[i] < src[j]) : (src[i] > src[j]))
            {
                helper[k++] = src[i++];
            }
            else
            {
                helper[k++] = src[j++];
            }
        }

        //看是否左边的所有元素是否达到尾部
        while (i <= mid) {
            helper[k++] = src[i++];
        }

        //右边的所有元素是否达到尾部
        while (j <= end) {
            helper[k++] = src[j++];
        }

        //将辅助空间中的有序元素拷贝到原数组中
        for(i = begin; i <= end; i++)
        {
            src[i] = helper[i];
        }

    }


    template<typename T>
    //将src这个数组里的元素排序，需要使用辅助数组helper，开始位置为begin结束为end
    static void Merge(T src[], T helper[], int begin, int end, bool min2max)
    {
        //只有一个元素时不用归并直接有序
        if(begin < end)
        {
            //均分两路
            int mid = (begin + end) / 2;

            //左半路归并
            Merge(src, helper, begin, mid, min2max);
            //右半路归并
            Merge(src, helper, mid + 1, end, min2max);

            Merge(src, helper, begin, mid, end, min2max);
        }
    }

    template<typename T>
    //找出基准下标
    static int Partition(T array[], int begin, int end, bool min2max)
    {
        //基准
        T pv = array[begin];

        while (begin < end)
        {
            //判断基准和数组末尾元素大小
            while ((begin < end) && (min2max ? (array[end] > pv) : (array[end] < pv))) {
                end--;
            }

            //交换基准
            Swap(array[begin], array[end]);

            //如果数组的第一个元素此时比基准小则
            while ((begin < end) && (min2max ? (array[begin] <= pv) : (array[begin] >= pv))) {
                begin++;
            }

            //大于基准时则交换
            Swap(array[begin], array[end]);
        }

        //基准就位
        array[begin] = pv;

        //返回基准下标
        return  begin;
    }

    //快排真正递归函数
    template<typename T>
    static void Quick(T array[], int begin, int end, bool min2max = true)
    {
        if(begin < end)
        {
            int pivot = Partition(array, begin, end, min2max);

            Quick(array, begin, pivot - 1, min2max);
            Quick(array, pivot + 1, end, min2max);
        }
    }

public:
    template<typename T>
    //选择排序
    static void Select(T array[], int len, bool min2max = true)
    {
        for(int i = 0; i < len; i++)
        {
            int min = i;
            //查找最小的数据元素
            for(int j = i + 1; j < len; j++)
            {
                if(min2max ? (array[min] > array[j]) : (array[min] < array[j]))
                {
                    min = j;
                }
            }
            //只有不相等时才交换
            if(min != i)
            {
                Swap(array[i], array[min]);
            }
        }
    }

    template<typename T>
    static void Insert(T array[], int len, bool min2max = true)
    {
        //无序序列从第二个元素开始
        for(int i = 1; i < len; i++)
        {
            int k = i;
            T e = array[i];

            //作比较操作无序中取出一个元素和有序中元素从后往前依次比较
            for(int j = i - 1; (j >= 0) && (min2max ? (array[j] > e) : (array[j] < e)); j--)
            {
                array[j + 1] = array[j];
                //记录空出来的位置
                k = j;
            }
            //空出的位置元素就位
            if(k != i)
            {
                 array[k] = e;
            }

        }
    }


    //冒泡排序
    template<typename T>
    static void Bubble(T array[], int len, bool min2max = true)
    {
        bool exchange = true;
        for(int i = 0; (i < len) && exchange; i++)
        {
            exchange = false;
            for(int j = len - 1; j > i; j--)
            {
                if(min2max ? (array[j] < array[j - 1]) : (array[j] > array[j - 1]))
                {
                    Swap(array[j], array[j - 1]);
                    exchange = true;
                }
            }
        }
    }

    template<typename T>
    static void Shell(T array[], int len, bool min2max = true)
    {
        //间隔
        int d = len;
        //多做几次插入排序
        do
        {
            //实践证明这样比较好可以提高效率
            d = d / 3 + 1;

            for(int i = d; i < len; i += d)
            {
                int k = i;
                T e = array[i];

                //作比较操作无序中取出一个元素和有序中元素从后往前依次比较
                for(int j = i - d; (j >= 0) && (min2max ? (array[j] > e) : (array[j] < e)); j -= d)
                {
                    array[j + d] = array[j];
                    //记录空出来的位置
                    k = j;
                }
                //空出的位置元素就位
                if(k != i)
                {
                     array[k] = e;
                }
            }

        }while(d > 1);
    }


    template<typename T>
    static void Merge(T array[], int len, bool min2max = true)
    {
        T* helper = new T[len];


        if(helper != NULL)
        {
            Merge(array, helper, 0, len - 1, min2max);
        }

        delete [] helper;
    }

    template<typename T>
    static void Quick(T array[], int len, bool min2max = true)
    {
        Quick(array, 0, len - 1, min2max);
    }

    template<typename T>
    static void Select(Array<T>& array, bool min2max = true)
    {
        Select(array.array(), array.length(), min2max);
    }

    template<typename T>
    static void Insert(Array<T>& array, bool min2max = true)
    {
        Insert(array.array(), array.length(), min2max);
    }

    template<typename T>
    static void Bubble(Array<T>& array, bool min2max = true)
    {
        Bubble(array.array(), array.length(), min2max);
    }

    template<typename T>
    static void Shell(Array<T>& array, bool min2max = true)
    {
        Shell(array.array(), array.length(), min2max);
    }


    template<typename T>
    static void Merge(Array<T>& array, bool min2max = true)
    {
        Merge(array.array(), array.length(), min2max);
    }

    template<typename T>
    static void Quick(Array<T>& array, bool min2max = true)
    {
        Quick(array.array(), array.length(), min2max);
    }


};


}



#endif // SORT_H
