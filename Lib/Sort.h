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
    //��src����������Ԫ��������Ҫʹ�ø�������helper����ʼλ��Ϊbegin����Ϊend
    static void Merge(T src[], T helper[], int begin, int mid, int end, bool min2max)
    {
        //���߿ռ���ʼλ��
        int i = begin;
        //�Ұ�߿ռ���ʼλ��
        int j = mid + 1;
        //����������ʼλ��
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

        //���Ƿ���ߵ�����Ԫ���Ƿ�ﵽβ��
        while (i <= mid) {
            helper[k++] = src[i++];
        }

        //�ұߵ�����Ԫ���Ƿ�ﵽβ��
        while (j <= end) {
            helper[k++] = src[j++];
        }

        //�������ռ��е�����Ԫ�ؿ�����ԭ������
        for(i = begin; i <= end; i++)
        {
            src[i] = helper[i];
        }

    }


    template<typename T>
    //��src����������Ԫ��������Ҫʹ�ø�������helper����ʼλ��Ϊbegin����Ϊend
    static void Merge(T src[], T helper[], int begin, int end, bool min2max)
    {
        //ֻ��һ��Ԫ��ʱ���ù鲢ֱ������
        if(begin < end)
        {
            //������·
            int mid = (begin + end) / 2;

            //���·�鲢
            Merge(src, helper, begin, mid, min2max);
            //�Ұ�·�鲢
            Merge(src, helper, mid + 1, end, min2max);

            Merge(src, helper, begin, mid, end, min2max);
        }
    }

    template<typename T>
    //�ҳ���׼�±�
    static int Partition(T array[], int begin, int end, bool min2max)
    {
        //��׼
        T pv = array[begin];

        while (begin < end)
        {
            //�жϻ�׼������ĩβԪ�ش�С
            while ((begin < end) && (min2max ? (array[end] > pv) : (array[end] < pv))) {
                end--;
            }

            //������׼
            Swap(array[begin], array[end]);

            //�������ĵ�һ��Ԫ�ش�ʱ�Ȼ�׼С��
            while ((begin < end) && (min2max ? (array[begin] <= pv) : (array[begin] >= pv))) {
                begin++;
            }

            //���ڻ�׼ʱ�򽻻�
            Swap(array[begin], array[end]);
        }

        //��׼��λ
        array[begin] = pv;

        //���ػ�׼�±�
        return  begin;
    }

    //���������ݹ麯��
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
    //ѡ������
    static void Select(T array[], int len, bool min2max = true)
    {
        for(int i = 0; i < len; i++)
        {
            int min = i;
            //������С������Ԫ��
            for(int j = i + 1; j < len; j++)
            {
                if(min2max ? (array[min] > array[j]) : (array[min] < array[j]))
                {
                    min = j;
                }
            }
            //ֻ�в����ʱ�Ž���
            if(min != i)
            {
                Swap(array[i], array[min]);
            }
        }
    }

    template<typename T>
    static void Insert(T array[], int len, bool min2max = true)
    {
        //�������дӵڶ���Ԫ�ؿ�ʼ
        for(int i = 1; i < len; i++)
        {
            int k = i;
            T e = array[i];

            //���Ƚϲ���������ȡ��һ��Ԫ�غ�������Ԫ�شӺ���ǰ���αȽ�
            for(int j = i - 1; (j >= 0) && (min2max ? (array[j] > e) : (array[j] < e)); j--)
            {
                array[j + 1] = array[j];
                //��¼�ճ�����λ��
                k = j;
            }
            //�ճ���λ��Ԫ�ؾ�λ
            if(k != i)
            {
                 array[k] = e;
            }

        }
    }


    //ð������
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
        //���
        int d = len;
        //�������β�������
        do
        {
            //ʵ��֤�������ȽϺÿ������Ч��
            d = d / 3 + 1;

            for(int i = d; i < len; i += d)
            {
                int k = i;
                T e = array[i];

                //���Ƚϲ���������ȡ��һ��Ԫ�غ�������Ԫ�شӺ���ǰ���αȽ�
                for(int j = i - d; (j >= 0) && (min2max ? (array[j] > e) : (array[j] < e)); j -= d)
                {
                    array[j + d] = array[j];
                    //��¼�ճ�����λ��
                    k = j;
                }
                //�ճ���λ��Ԫ�ؾ�λ
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
