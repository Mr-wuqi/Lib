/*#include <iostream>
#include "SmartPointer.h"

using namespace std;
using namespace Lib;

class Test
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
    }
};

int main()
{
    SmartPointer<Test> t1 = new Test();
    SmartPointer<Test> t2 = t1;

    cout << t1.isNull() << endl;
    cout << t2.isNull() << endl;

    return 0;
}*/

/*#include <iostream>
#include "Exception.h"

using namespace Lib;
using namespace std;

int main()
{
    try
    {
        THROW_EXCEPTION(ArithmeticException, "Test");
    }
    catch(const ArithmeticException& e)
    {
        cout << "catch(const ArithmeticException& e)" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    }
    catch(const Exception& e)
    {
        cout << "catch(const Exceprion& e)" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    return 0;
}*/

/*#include <iostream>
#include "Object.h"

using namespace std;
using namespace Lib;

class Test : public Object
{
public:
    int i;
    int j;
};

class Child : public Test
{
public:
    int k;
};


int main()
{
    Object* obj1 = new Test();
    Object* obj2 = new Child();

    delete obj1;
    delete obj2;
    return 0;
}*/

/*#include <iostream>
#include "SmartPointer.h"

using namespace Lib;
using namespace std;

class Test
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
    }
};

int main()
{
    SmartPointer<Test> sp = new Test();


    return 0;
}*/

/*#include <iostream>
#include "StaticList.h"
#include "DynamicList.h"
#include "Exception.h"

using namespace std;
using namespace Lib;

int main()
{
    StaticList<int, 5> sl;

    for(int i = 0; i < sl.capacity(); i++)
    {
        sl.insert(0,i);
    }

    for(int i = 0; i < 5; i++)
    {
        cout << sl[i] << endl;
    }



    try
    {
        sl[5] = 5;
    }
    catch(const Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    return 0;
}*/

/*#include <iostream>
#include "DynamicList.h"

using namespace Lib;
using namespace std;

int main()
{
    DynamicList<int> dl(5);


    for(int i = 0; i < dl.capacity(); i++)
    {
        dl.insert(0, i);
    }

    for(int i = 0; i < dl.length(); i++)
    {
        cout << dl[i] << endl;
    }

    cout << endl;
    dl.resize(10);

    dl.insert(5, 100);

    for(int i = 0; i < dl.length(); i++)
    {
        cout << dl[i] << endl;
    }


    return 0;
}*/


/*#include <iostream>
#include "StaticArray.h"
#include "Exception.h"

using namespace std;
using namespace Lib;

int main()
{
    StaticArray<int, 5> s1;

    for(int i = 0; i < s1.length(); i++)
    {
        s1[i] = i * i;
    }

    for(int i = 0; i < s1.length(); i++)
    {
        cout << s1[i] << endl;
    }

    cout << endl;

    StaticArray<int, 5> s2;

    s2 = s1;

    for(int i = 0; i < s2.length(); i++)
    {
        cout <<s2[i] << endl;
    }

    try
    {
       s2[6] = 100;
    }
    catch(const Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    return 0;
}*/

/*#include <iostream>
#include "DynamicArray.h"

using namespace std;
using namespace Lib;

int main()
{
    DynamicArray<int> da(5);

    for(int i = 0; i < da.length(); i++)
    {
        da[i] = i * i;
    }

    for(int i = 0; i < da.length(); i++)
    {
        cout << da[i] << endl;
    }

    da.resize(6);

    da[5] = 10;

    cout << da[5] << endl;

    da.resize(3);

    for(int i = 0; i < da.length(); i++)
    {
        cout << da[i] << endl;
    }

    DynamicArray<int> s2(5);

    s2 = da;

    return 0;
}*/


/*#include <iostream>
#include "LinkList.h"


using namespace Lib;
using namespace std;

class Test : public Object
{
    int i;
public:
    Test(int v = 0)
    {
        i = v;
    }

    bool operator == (const Test& t)
    {
        return (i == t.i);
    }
};

int main()
{
    LinkList<int> list;

    for(int i = 0; i < 5; i++)
    {
        list.insert(0, i);
    }

    for(int i = 0; i < list.length(); i++)
    {
        cout << list.get(i) << endl;
    }

    list.remove(2);



    cout << endl;

    for(int i = 0; i < list.length(); i++)
    {
        cout << list.get(i) << endl;
    }

    cout << list.find(3) << endl;

    Test t1(1);
    Test t2(2);
    Test t3(3);
    LinkList<Test> list;

    list.insert(t1);
    list.insert(t2);
    list.insert(t3);

    cout << list.find(t2) << endl;


    return 0;
}*/


/*#include <iostream>
#include "LinkList.h"

using namespace Lib;
using namespace std;

int main()
{

    LinkList<int> list;

    for(int i = 0; i < 5; i++)
    {
        list.insert(0, i);
    }

    for(list.move(0); !list.end(); list.next())
    {
        cout << list.current() << endl;
    }

    return 0;
}*/

/*#include <iostream>
#include "StaticLinkList.h"

using namespace std;
using namespace Lib;



int main()
{
    StaticLinkList<int, 5> list;

    for(int i = 0; i < 5; i++)
    {
        list.insert(0, i);
    }

    //list.insert(5, 6);

    for(list.move(0); !list.end(); list.next())
    {
        cout << list.current() << endl;
    }
    return 0;
}*/


/*#include <iostream>
#include "Exception.h"

using namespace std;
using namespace Lib;

int main()
{
    try
    {
        NullPointerException npe;

        cout << "throw" << endl;

        throw npe;
    }
    catch(const Exception& e)
    {
        cout << "catch" << endl;
    }

    return 0;
}*/

//gcc编译器不允许在析构函数中抛出异常
/*#include <iostream>
#include "LinkList.h"

using namespace std;
using namespace Lib;

class Test : public Object
{
    int m_id;
public:
    Test(int id = 0)
    {
        m_id = id;
    }

    ~Test()
    {
        if( m_id == 1 )
        {
            throw m_id;
        }
    }
};

int main()
{
    LinkList<Test> list;
    Test t0(0), t1(1), t2(2);

    try
    {
        list.insert(t0);
        list.insert(t1);
        list.insert(t2);

        list.remove(1);
    }
    catch(int e)
    {
        cout << e << endl;
        cout << list.length() << endl;
    }

    return 0;
}*/

/*#include <iostream>
#include "LinkList.h"

using namespace std;
using namespace Lib;

int main()
{
    LinkList<int> list;

    for(int i=0; i<5; i++)
    {
        list.insert(i);
    }

    for(list.move(0); !list.end(); list.next())
    {
        if( list.current() == 3 )
        {
            list.remove(list.find(list.current()));

            cout <<list.current() << endl;
        }
    }

    for(int i=0; i<list.length(); i++)
    {
        cout << list.get(i) << endl;
    }

    return 0;
}*/

/*#include <iostream>
#include "StaticLinkList.h"

using namespace std;
using namespace Lib;

int main()
{
    StaticLinkList<int, 10> list;

    for(int i=0; i<5; i++)
    {
        list.insert(i);
    }

    for(int i=0; i<list.length(); i++)
    {
        cout << list.get(i) << endl;
    }

    return 0;
}*/

/*#include <iostream>
#include "StaticLinkList.h"
#include "DynamicArray.h"

using namespace std;
using namespace Lib;

int main()
{
    DynamicArray< DynamicArray<int> > d;

    d.resize(3);

    for(int i=0; i<d.length(); i++)
    {
        d[i].resize(i + 1);
    }

    for(int i=0; i<d.length(); i++)
    {
        for(int j=0; j<d[i].length(); j++)
        {
            d[i][j] = i + j;
        }
    }

    for(int i=0; i<d.length(); i++)
    {
        for(int j=0; j<d[i].length(); j++)
        {
            cout << d[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}*/

/*#include <iostream>
#include "SmartPointer.h"

using namespace std;
using namespace Lib;

class Test
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
    }
};

int main()
{
    SmartPointer<Test> pt = new Test();

    SmartPointer<Test> spt;

    spt = pt;

    return 0;
}*/

/*#include <iostream>
#include "Exception.h"
#include "SharedPointer.h"
using namespace Lib;

class Test
{
public:
    int value;
    Test() : value(0)
    {
        std::cout << "Test()" << std::endl;
    }

    ~Test()
    {
        std::cout << "~Test()" << std::endl;
    }
};

int main()
{
    SharedPointer<Test> sp0 = new Test();
    SharedPointer<Test> sp1 = sp0;


    SharedPointer<Test> sp2 = NULL;
    sp2 = sp1;

    sp2->value = 100;

    std::cout << sp0->value << std::endl;
    std::cout << sp1->value << std::endl;
    std::cout << sp2->value << std::endl;

    std::cout << (sp0 == sp1) << std::endl;

    return 0;
}*/

/*#include <iostream>
#include "CircleList.h"

using namespace std;
using namespace Lib;

void josephus(int n, int s, int m)
{
    CircleList<int> cl;

    for(int i = 1; i <= n; i++)
    {
        cl.insert(i);
    }

    cl.move(s-1, m - 1);

    while(cl.length() > 0)
    {
        cl.next();

        cout << cl.current() << endl;

        cl.remove(cl.find(cl.current()));
    }
}

int main()
{

    josephus(41, 1, 3);
    return 0;
}
*/

/*#include <iostream>
#include "DualLinkList.h"

using namespace std;
using namespace Lib;

int main()
{
    DualLinkList<int> dl;

    for(int i = 0; i < 5; i++)
    {
        dl.insert(0, i);
        dl.insert(0, 5);
    }


    cout << "Begin..." << endl;

    dl.move(dl.length() - 1);

    while(!dl.end())
    {
        if(dl.current() == 5)
        {
            cout << dl.current() << endl;

            dl.remove(dl.find(dl.current()));
        }
        else
        {
            dl.pre();
        }
    }

    cout << "End..." << endl;


    for(dl.move(0); !dl.end(); dl.next())
    {
        cout << dl.current() << endl;
    }


    return 0;
}
*/

/*#include <iostream>
#include "DualCircleList.h"

using namespace std;
using namespace Lib;

int main()
{
    DualCircleList<int> dl;

    for(int i = 0; i < 5; i++)
    {
        dl.insert(0, i);
        dl.insert(0, 5);
    }


    cout << "Begin..." << endl;

    dl.move(dl.length() - 1);

    while(dl.find(5) != -1)
    {
        if(dl.current() == 5)
        {
            cout << dl.current() << endl;

            dl.remove(dl.find(dl.current()));
        }
        else
        {
            dl.pre();
        }
    }

    cout << "End..." << endl;


    int i = 0;
    for(dl.move(dl.length() - 1); (i < dl.length()) && !dl.end(); dl.pre(),i++)
    {
        cout << dl.current() << endl;
    }


    return 0;
}*/

/*#include <iostream>
#include "StaticStack.h"

using namespace Lib;
using namespace std;

int main()
{
    StaticStack<int, 5> stack;

    try {
        stack.pop();
    } catch (const Exception& e) {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    for(int i = 0; i < 5; i++)
    {
        stack.push(i);
    }

    while (stack.size() > 0) {
        cout << stack.top() << endl;

        stack.pop();
    }
    return  0;
}

#include <iostream>
#include "StaticStack.h"

using namespace Lib;
using namespace std;

class Test
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
    }
};

int main()
{

    StaticStack<Test, 10> stack;

    cout << stack.size() << endl;

    return  0;
}*/

/*#include <iostream>
#include "LinkStack.h"

using namespace Lib;
using namespace std;

int main()
{

    LinkStack<int> stack;

    for(int i = 0; i < 5; i++)
    {
        stack.push(i);
    }

    while (stack.size() > 0) {
        cout << stack.top() << endl;
        stack.pop();
    }

    cout << stack.size() << endl;

    return  0;
}*/

/*#include <iostream>
#include "LinkStack.h"

using namespace Lib;
using namespace std;

bool is_left(char c)
{
    return  (c == '(') || (c == '{') || (c == '[') || (c == '<');
}

bool is_right(char c)
{
    return  (c == ')') || (c == '}') || (c == ']') || (c == '>');
}

bool is_quot(char c)
{
    return  (c == '\'') || (c == '\"');
}

bool is_match(char l, char r)
{
    return  ((l == '(') && (r == ')')) ||
            ((l == '{') && (r == '}')) ||
            ((l == '[') && (r == ']')) ||
            ((l == '<') && (r == '>')) ||
            ((l == '\'') && (r == '\'')) ||
            ((l == '\"') && (r == '\"'));
}

bool scan(const char* code)
{
    LinkStack<char> stack;
    int i = 0;
    bool ret = true;

    code = (code == NULL) ? "" : code;

    while (ret && (code[i] != '\0')) {
        if(is_left(code[i]))
        {
            stack.push(code[i]);
        }
        else if(is_right(code[i]))
        {
            if((stack.size() > 0) && is_match(stack.top(), code[i]))
            {
                stack.pop();
            }
            {
                ret = false;
            }
        }
        else if(is_quot(code[i]))
        {
            if((stack.size() == 0) || !is_match(stack.top(), code[i]))
            {
                stack.push(code[i]);
            }
            else if(is_match(stack.top(), code[i]))
            {
                stack.pop();
            }
        }
        i++;
    }

    return  ret && (stack.size() == 0);
}

int main()
{
    cout << scan("<>") << endl;
    return  0;
}*/

/*#include <iostream>
#include "StaticQueue.h"

using namespace std;
using namespace Lib;

int main()
{

    StaticQueue<int, 5> queue;
    for(int i = 0; i < 5; i++)
    {
        queue.add(i);
    }

    while (queue.length() > 0) {
        cout << queue.front() << endl;

        queue.remove();
    }

    return  0;
}*/

/*#include <iostream>
#include "LinkQueue.h"
#include "StaticQueue.h"

using namespace std;
using namespace Lib;

class Test : public Object
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
    }
};

int main()
{
    LinkQueue<Test> lq;
    StaticQueue<Test, 10> sq;
    for(int i = 0; i < 10; i++)
    {
        //lq.add(i);
    }

    while (lq.length() > 0) {
        //cout << lq.front() << endl;

        lq.remove();
    }
    return  0;
}*/

/*#include <iostream>
#include "LinkStack.h"
#include "LinkQueue.h"

using namespace std;
using namespace Lib;

template  <typename T>
class StackToQueue : public Queue<T>
{
protected:
    mutable LinkStack<T> m_stack_in;
    mutable LinkStack<T> m_stack_out;

    //O(n)
    void move() const
    {
        if(m_stack_out.size() == 0)
        {
            while (m_stack_in.size() > 0) {
                m_stack_out.push(m_stack_in.top());
                m_stack_in.pop();
            }
        }
    }

public:
    //O(1)
    void add(const T& e)
    {
        m_stack_in.push(e);
    }

    //O(n)
    void remove()
    {

        move();
        if(m_stack_out.size() > 0)
        {
            m_stack_out.pop();
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No element in current stack...");
        }
    }

    //O(n)
    T front() const
    {


        move();
        if(m_stack_out.size() > 0)
        {
            return  m_stack_out.top();
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No element in current queue...");
        }
    }

    //O(n)
    void clear()
    {
        m_stack_in.clear();
        m_stack_out.clear();
    }

    //O(1)
    int length() const
    {
        return  m_stack_in.size() + m_stack_out.size();
    }
};

int main()
{
    StackToQueue<int> sq;

    for(int i = 0; i < 10; i++)
    {
        sq.add(i);
    }

    while (sq.length() > 0) {
        cout << sq.front() << endl;

        sq.remove();
    }
    return 0;
}*/

/*#include <iostream>
#include "LinkStack.h"
#include "LinkQueue.h"

using namespace std;
using namespace Lib;

template <typename T>
class QueueToStack : public Stack<T>
{
protected:
    LinkQueue<T> m_queue_1;
    LinkQueue<T> m_queue_2;
    //定义角色分辨入队和出队
    LinkQueue<T>* m_pIn;
    LinkQueue<T>* m_pOut;

    //将进队列里的前n-1个元素全部转移到出队列中
    //O(n)
    void move() const
    {
        int n = m_pIn->length() - 1;

        for(int i = 0; i < n; i++)
        {
            m_pOut->add(m_pIn->front());
            m_pIn->remove();
        }
    }

    //O(1)
    //交换两个队列的角色循环执行操作
    void swap()
    {
        LinkQueue<T>* temp = NULL;

        temp = m_pIn;
        m_pIn = m_pOut;
        m_pOut = temp;
    }

public:
    //O(1)
    QueueToStack()
    {
        m_pIn = &m_queue_1;
        m_pOut = &m_queue_2;
    }

    //O(1)
    void push(const T& e)
    {
        m_pIn->add(e);
    }
    //O(n)
    void pop()
    {
        if(m_pIn->length() > 0)
        {
            move();

            m_pIn->remove();

            swap();
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No element in current stack...");
        }
    }

    //O(n)
    T top() const
    {
        if(m_pIn->length() > 0)
        {
            move();

            //弹出进队列的最后一个元素，即栈顶元素
            return  m_pIn->front();
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No element in current stack...");
        }
    }

    //O(n)
    void clear()
    {
        m_queue_1.clear();
        m_queue_2.clear();
    }

    //O(1)
    int size() const
    {
        return  m_queue_1.length() + m_queue_2.length();
    }

};

int main()
{
    QueueToStack<int> sq;

    for(int i = 0; i < 10; i++)
    {
        sq.push(i);
    }

    while (sq.size() > 0) {
        cout << sq.top() << endl;

        sq.pop();
    }
    return 0;
}*/

/*#include <iostream>
#include "MyString.h"

using namespace Lib;
using namespace std;

void test_1()
{
    cout << "Begin..." << endl;

    String s;

    s = 'H';

    cout << s.str() << endl;
    cout << s.length() << endl;
    cout << (s == "H") << endl;
    cout << (s > "CCC") << endl;

    s += "llo, world";

    cout << s.str() << endl;
    cout << s.length() << endl;

    cout << "End..." << endl;
}

void test_2()
{
    cout << "Begin..." << endl;

    String a[] = {"H", "E", "L", "L", "O"};
    String min = a[0];
    for(int i = 0; i < 5; i++)
    {
        if(min > a[i])
        {
            min = a[i];
        }
    }

    cout << "min = " << min.str() << endl;

    cout << "End..." << endl;
}

int main()
{
    //test_1();
    test_2();
    return  0;
}*/


/*#include <iostream>
#include "MyString.h"

using namespace Lib;
using namespace std;

int main()
{

    String s = "  ss    ";

    if(s.trim().insert(0, "Hell").endOf("ss") && s.startWith("Hell"))
    {
        cout << s.str() << endl;
    }

    return  0;
}*/

/*#include <iostream>
#include <cstring>
//#include "MyString.h"

using namespace std;
//using namespace Lib;

//求出部分匹配表函数，并返回部分匹配表
int* make_pmt(const char* p)
{
    int len = static_cast<int>(strlen(p));
    int* ret = reinterpret_cast<int*>(malloc(sizeof (int) * static_cast<unsigned int>(len)));

    if(ret)
    {
        //前缀后缀交集中最大的重复元素长度
        int ll = 0;
        ret[0] = 0;
        for(int i = 1; i < len; i++)
        {
            //如果不成功
            while((ll > 0) && (p[ll] != p[i]))
            {
                ll = ret[ll - 1];
            }

            //在前一个ll值的基础上进行扩展
            if(p[ll] == p[i])
            {
                ll++;
            }

            ret[i] = ll;
        }
    }

    return  ret;
}

int kmp(const char* s, const char* p)
{
    int ret = -1;
    int sl = static_cast<int>(strlen(s));
    int pl = static_cast<int>(strlen(p));

    int* pmt = make_pmt(p);

    if((pmt != NULL) && (0 < pl) && (pl <= sl))
    {
        for(int i = 0, j = 0; i < sl; i++)
        {
            while((s[i] != p[j]) && (j > 0))
            {
                j = pmt[j - 1];
            }

            if(s[i] == p[j])
            {
                j++;
            }

            if(j == pl)
            {
                ret = i + 1 - pl;
                break;
            }
        }
    }

    free(pmt);
    return  ret;
}

int main()
{
    cout << kmp("ababax", "ababaxy") << endl;
    return  0;
}*/

/*#include <iostream>
#include <cstring>
#include "MyString.h"
using namespace std;
using namespace Lib;
int main()
{
    String s = "ababax";
    String s1 = s.sub(3, 2);
    cout << s1.str() << endl;
    return  0;
}*/

/*#include <iostream>
#include "Object.h"
#include "LinkList.h"

using namespace Lib;
using namespace std;

struct Node
{
    int value;
    Node* next;
};

Node* create_list(int v, int len)
{
    Node* ret = NULL;
    Node* slider = NULL;

    for(int i = 0; i < len; i++)
    {
        Node* n = new Node();

        n->value = v++;
        n->next = NULL;

        if(slider == NULL)
        {
            slider = n;
            ret = n;
        }
        else
        {
           slider->next = n;
           slider = n;
        }
    }

    return  ret;
}

void destroy_list(Node* list)
{
    while (list) {
        Node* toDel = list;

        list = list->next;

        delete toDel;

    }
}

void print_list(Node* list)
{
    while (list) {
        cout << list->value << "->";

        list = list->next;
    }
    cout << "NULL" << endl;
}

Node*  reverse(Node* list)
{
    if((list == NULL) || (list->next == NULL))
    {
        return list;
    }
    else
    {
        Node* guard = list->next;
        Node* ret = reverse(list->next);

        guard->next = list;
        list->next = NULL;

        return  ret;
    }
}

Node* merge(Node* list1, Node* list2)
{
    if(list1 == NULL)
    {
        return list2;
    }else if(list2 == NULL)
    {
        return list1;
    }else
    {
        if(list1->value <= list2->value)
        {
            Node* list1_ = list1->next;
            Node* list = merge(list1_, list2);

            list1->next = list;

            return list1;
        }
        else
        {
            Node* list2_ = list2->next;
            Node* list = merge(list1, list2_);

            list2->next = list;

            return list2;
        }
    }
}

template<int SIZE>
class QueueSolution : public Object
{

protected:
    //在棋盘外围加两行两列便于执行算法
    enum { N = SIZE + 2 };

    //坐标结构体
    struct Pos : public Object
    {
        Pos(int px = 0, int py = 0) : x(px),y(py){}
        int x;
        int y;
    };

    //棋盘
    int m_chessboard[N][N];
    //位置，左下，正下，右下方向是否有皇后存在
    Pos m_direction[3];
    //链表存储解决方案
    LinkList<Pos> m_solution;
    //方案计数
    int m_count;

    //初始化成员
    void init()
    {
        m_count = 0;

        //将边界行初始化为2
        for(int i = 0; i < N; i += (N - 1))
        {
            for(int j = 0; j < N; j++)
            {
                m_chessboard[i][j] = 2;
                m_chessboard[j][i] = 2;
            }
        }

        //将内部棋盘初始化位0
        for(int i = 1; i <= SIZE; i++)
        {
            for(int j = 1; j <= SIZE; j++)
            {
                m_chessboard[i][j] = 0;
            }
        }

        //三个方位初始化
        m_direction[0].x = -1;
        m_direction[0].y = -1;
        m_direction[1].x = 0;
        m_direction[1].y = -1;
        m_direction[2].x = 1;
        m_direction[2].y = -1;
    }

    //打印函数
    void print()
    {

        //将皇后坐标存入链表中，便于输出显示
        for(m_solution.move(0); !m_solution.end(); m_solution.next())
        {
            cout << "(" << m_solution.current().x << "," << m_solution.current().y << ") ";
        }

        cout << endl;

        //填充棋盘如果有皇后则打印#,边界打印*,无皇后区域打印空格
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                switch (m_chessboard[i][j])
                {
                    case 0: cout << " " ; break;
                    case 1: cout << "#" ; break;
                    case 2: cout << "*" ; break;
                }
            }

            cout << endl;
        }

        cout << endl;
    }

    //如果返回true证明当前位置的一个方向上有没有皇后
    bool check(int x, int y, int d)
    {
        bool flag = true;

        do
        {
            x += m_direction[d].x;
            y += m_direction[d].y;
            //检查当前位置是否放了皇后，这个while的退出条件是遇见边界
            flag = flag && (m_chessboard[x][y] == 0);
        }
        while(flag);

        return (m_chessboard[x][y] == 2);
    }

    //执行函数
    void run(int j)
    {
        //每一行一次填放
        if(j <= SIZE)
        {
            for(int i = 1; i <= SIZE; i++)
            {
                //检查此位置的三个方向上是否都没有其他皇后
                if(check(i, j, 0) && check(i, j, 1) && check(i, j, 2))
                {
                    //如果没有则将皇后填入
                    m_chessboard[i][j] = 1;
                    //将皇后坐标加到链表中
                    m_solution.insert(Pos(i, j));

                    //递归依次向上遍历，如果最后一行不能放皇后则回溯
                    run(j + 1);

                    //回溯清0
                    m_chessboard[i][j] = 0;

                    //将加入链表的最后一个元素删除
                    m_solution.remove(m_solution.length() - 1);
                }
            }
        }
        else
        {
            m_count++;

            //打印解决方案
            print();
        }
    }

public:
    QueueSolution()
    {
        init();
    }

    void run()
    {
        run(1);

        cout << "Total : " << m_count << endl;
    }
};


int main()
{
    QueueSolution<6> qs;

    qs.run();

    return  0;
}*/

/*#include <iostream>
#include "Sort.h"
#include "StaticArray.h"

using namespace std;
using namespace Lib;


int main()
{

    StaticArray<double, 5> sa;

    for(int i = 0; i < 5; i++)
    {
        sa[i] = i;
    }

    Sort::Insert(sa, false);

    for(int i = 0; i < sa.length(); i++)
    {
        cout << sa[i] << endl;
    }

    return 0;
}*/

/*#include <iostream>
#include "Object.h"
#include <ctime>
#include "Sort.h"

using namespace std;
using namespace Lib;


struct Test : public Object
{
    int id;
    int data1[1000];
    double data2[1000];

    bool operator < (const Test& obj)
    {
        return  id < obj.id;
    }

    bool operator >= (const Test& obj)
    {
        return  id >= obj.id;
    }

    bool operator > (const Test& obj)
    {
        return  id > obj.id;
    }

    bool operator <= (const Test& obj)
    {
        return  id <= obj.id;
    }
};

class TestProxy : public Object
{

protected:
    Test* m_pTest;

public:
    int id()
    {
        return m_pTest->id;
    }

    int* data1()
    {
        return m_pTest->data1;
    }

    double* data2()
    {
        return m_pTest->data2;
    }

    Test& test() const
    {
        return *m_pTest;
    }

    bool operator < (const TestProxy& obj)
    {
        return  test() < obj.test();
    }

    bool operator > (const TestProxy& obj)
    {
        return  test() > obj.test();
    }

    bool operator <= (const TestProxy& obj)
    {
        return  test() <= obj.test();
    }

    bool operator >= (const TestProxy& obj)
    {
        return  test() >= obj.test();
    }

    Test& operator = (Test& test)
    {
        m_pTest = &test;

        return  test;
    }
};


Test t[1000];
TestProxy pt[1000];

int main()
{
    clock_t begin = 0;
    clock_t end = 0;
    for(int i = 0; i < 1000; i++)
    {
        t[i].id = i;
        pt[i] = t[i];
    }

    begin = clock();
    Sort::Bubble(pt, 1000, false);

    end = clock();

    cout << "Time: " << end - begin << endl;

    for(int i = 0; i < 1000; i++)
    {
        cout << t[i].id << " " << pt[i].id() << endl;
    }

    return  0;
}*/


/*#include <iostream>
#include "GTree.h"

using namespace std;
using namespace Lib;

int main()
{
    GTree<int> t;
    GTreeNode<int> tn;

    t.find(0);
    t.find(&tn);

    return 0;
}*/

/*#include <iostream>
#include "GTree.h"
#include "BTree.h"
#include "SharedPointer.h"

using namespace std;
using namespace Lib;

int main()
{

    GTree<char> t;
    GTreeNode<char>* node = NULL;
    GTreeNode<char> root;

    root.value = 'A';
    root.parent = NULL;

    t.insert(&root);

    node = t.find('A');
    t.insert('B', node);
    t.insert('C', node);
    t.insert('D', node);

    node = t.find('B');
    t.insert('E', node);
    t.insert('F', node);

    node = t.find('E');
    t.insert('K', node);
    t.insert('L', node);

    node = t.find('C');
    t.insert('G', node);

    node = t.find('D');
    t.insert('H', node);
    t.insert('I', node);
    t.insert('J', node);

    node = t.find('H');
    t.insert('M', node);

    //t.clear();

    SharedPointer< Tree<char> > p = t.remove(t.find('D'));

    const char* s = "KLFGMIJ";

    for(int i = 0; i < 7; i++)
    {
        TreeNode<char>* node = p->find(s[i]);

        while (node != NULL) {
            cout << node->value << " ";

            node = node->parent;
        }

        cout << endl;
    }

    cout << t.count() << endl;
    cout << t.height() << endl;
    cout << t.degree() << endl;

    for(t.begin(); !t.end(); t.next())
    {
        cout << t.current() << endl;
    }

    BTree<char> bt;
    BTreeNode<char> btn;
    //cout << "Hello" << endl;



    return 0;
}*/

/*#include <iostream>
#include "BTreeNode.h"
#include "BTree.h"

using namespace std;
using namespace Lib;

int main()
{
    BTree<int> bt;
    BTreeNode<int>* n = NULL;

    bt.insert(1, NULL);

    n = bt.find(1);
    bt.insert(2, n);
    bt.insert(3, n);

    n = bt.find(2);
    bt.insert(4, n);
    bt.insert(5, n);

    n = bt.find(4);
    bt.insert(8, n);
    bt.insert(9, n);

    n = bt.find(5);
    bt.insert(10, n);

    n = bt.find(3);
    bt.insert(6, n);
    bt.insert(7, n);


    cout << bt.count() << endl;
    cout << bt.height() << endl;
    cout << bt.degree() << endl;

    SharedPointer< BTree<int> > btClone = bt.clone();


    int a[] = {8, 9, 10, 7};

    cout << "Clone: " << endl;

    for(int i = 0; i < 5; i++)
    {
        TreeNode<int>* node = btClone->find(a[i]);

        while(node)
        {
            cout << node->value << " ";
            node = node->parent;
        }

        cout << endl;
    }

    cout << endl;

    cout << "Old: " << endl;

    for(int i = 0; i < 5; i++)
    {
        TreeNode<int>* node = bt.find(a[i]);

        while(node)
        {
            cout << node->value << " ";
            node = node->parent;
        }

        cout << endl;
    }


    SharedPointer< Array<int> > sp = NULL;

    sp = bt.traversal(PreOrder);

    for(int i = 0; i < (*sp).length(); i++)
    {
        cout << (*sp)[i] << " ";
    }

    cout << endl;

    cout << "*bt == *btn: " << (bt == *btClone) << endl;

    //再构建一个二叉树
    BTree<int> nbt;

    nbt.insert(0, NULL);
    n = nbt.find(0);
    nbt.insert(6, n);
    nbt.insert(2, n);

    n = nbt.find(2);
    nbt.insert(7, n);
    nbt.insert(8, n);

    SharedPointer< BTree<int> > r = bt.add(nbt);

    int a[] = {8, 9, 10, 13, 15};

    cout << "Add: " << endl;

    for(int i = 0; i < 5; i++)
    {
        TreeNode<int>* node = r->find(a[i]);

        while(node)
        {
            cout << node->value << " ";
            node = node->parent;
        }

        cout << endl;
    }

    SharedPointer< Array<int> > tr = r->traversal(InOrder);

    for(int i = 0; i < tr->length(); i++)
    {
        cout << (*tr)[i] << " ";
    }

    cout << endl;

    return 0;
}
*/

/*#include <iostream>
#include "BTreeNode.h"
#include "BTree.h"

using namespace std;
using namespace Lib;

int main()
{
    BTree<int> bt;
    BTreeNode<int>* n = NULL;

    bt.insert(1, NULL);

    n = bt.find(1);
    bt.insert(2, n);
    bt.insert(3, n);

    n = bt.find(2);
    bt.insert(4, n);
    bt.insert(5, n);

    n = bt.find(4);
    bt.insert(8, n);
    bt.insert(9, n);

    n = bt.find(5);
    bt.insert(10, n);

    n = bt.find(3);
    bt.insert(6, n);
    bt.insert(7, n);


    cout << bt.count() << endl;
    cout << bt.height() << endl;
    cout << bt.degree() << endl;

    SharedPointer< Array<int> > tr = bt.traversal(LevelOrder);

    for(int i = 0; i < tr->length(); i++)
    {
        cout << (*tr)[i] << " ";
    }

    cout << endl;

    BTreeNode<int>* head = bt.thread(LevelOrder);

    while(head->right != NULL)
    {
        head = head->right;
    }

    while(head != NULL)
    {
        cout << head->value << " ";
        head = head->left;
    }

    return 0;
}
*/

/*#include <iostream>
#include "BTreeNode.h"

using namespace std;
using namespace Lib;

//创建一个二叉树
template < typename T >
BTreeNode<T>* createTree()
{
    static BTreeNode<int> ns[9];

    for(int i=0; i<9; i++)
    {
        ns[i].value = i;
        ns[i].parent = NULL;
        ns[i].left = NULL;
        ns[i].right = NULL;
    }

    ns[0].left = &ns[1];
    ns[0].right = &ns[2];
    ns[1].parent = &ns[0];
    ns[2].parent = &ns[0];

    ns[1].left = &ns[3];
    ns[1].right = NULL;
    ns[3].parent = &ns[1];

    ns[2].left = &ns[4];
    ns[2].right = &ns[5];
    ns[4].parent = &ns[2];
    ns[5].parent = &ns[2];

    ns[3].left = NULL;
    ns[3].right = &ns[6];
    ns[6].parent = &ns[3];

    ns[4].left = &ns[7];
    ns[4].right = NULL;
    ns[7].parent = &ns[4];

    ns[5].left = &ns[8];
    ns[5].right = NULL;
    ns[8].parent = &ns[5];

    return ns;
}

//中序打印二叉树
template < typename T >
void printInOrder(BTreeNode<T>* node)
{
    if( node != NULL )
    {
        printInOrder(node->left);

        cout << node->value <<" ";

        printInOrder(node->right);
    }
}

//打印线索树
template < typename T >
void printDualList(BTreeNode<T>* node)
{
    BTreeNode<T>* g = node;

    cout << "head -> tail: " << endl;

    while( node != NULL )
    {
        cout << node->value << " ";

        g = node;

        node = node->right;
    }

    cout << endl;

    cout << "tail -> head: " << endl;

    while( g != NULL )
    {
        cout << g->value << " ";

        g = g->left;
    }

    cout << endl;
}

//删除度为1的节点，包含指向父节点的指针
template<typename T>
BTreeNode<T>* delOdd1(BTreeNode<T>* node)
{
    BTreeNode<T>* ret = NULL;
    if(node != NULL)
    {
        //如果度为1
        if(((node->left != NULL) && (node->right == NULL)) ||
           ((node->left == NULL) && (node->right != NULL))
          )
        {
            //定义一个指针指向node的父节点
            BTreeNode<T>* parent = dynamic_cast<BTreeNode<T>*>(node->parent);
            //node_child指向单度为一节点的那个孩子
            BTreeNode<T>* node_child = (node->left != NULL) ? node->left : node->right;

            if(parent != NULL)
            {
                //父节点的孩子指针
                BTreeNode<T>*& parent_child = (parent->left == node) ? parent->left : parent->right;

                parent_child = node_child;
                node_child->parent = parent;
            }
            else
            {
                node_child->parent = NULL;
            }

            //如果是从堆空间中申请的则delete
            if(node->flag())
            {
                delete node;
            }

            ret = delOdd1(node_child);
        }
        //度为2的情况
        else
        {
            delOdd1(node->left);

            delOdd1(node->right);

            //返回当前节点
            ret = node;
        }
    }
    return ret;
}

//删除树中度为一的节点，不包含指向父节点的指针
template <typename T>
void delOdd2(BTreeNode<T>*& node)
{

    if(node != NULL)
    {
        if(((node->left == NULL) && (node->right != NULL)) ||
           ((node->left != NULL) && (node->right == NULL)))
        {
            BTreeNode<T>* node_child = (node->left != NULL) ? node->left : node->right;

            if(node->flag())
            {
                delete node;
            }

            node = node_child;
            //因为node是一个引用，在这里是node的孩子的别名
            delOdd2(node);

        }
        else
        {
            delOdd2(node->left);
            delOdd2(node->right);
        }
    }

}

//中序线索化功能函数在这里不使用其他数据结构
template <typename T>
void inOrderTread(BTreeNode<T>* node, BTreeNode<T>*& pre)
{
    if(node != NULL)
    {
        inOrderTread(node->left, pre);

        node->left = pre;

        if(pre != NULL)
        {
            pre->right = node;
        }

        pre = node;

        inOrderTread(node->right, pre);
    }
}

template <typename T>
BTreeNode<T>* inOrderTread1(BTreeNode<T>* node)
{
    BTreeNode<T>* pre = NULL;

    inOrderTread(node, pre);

    while((node != NULL) && (node->left != NULL))
    {
        node = node->left;
    }

    return node;
}


//中序线索化功能函数
template <typename T>
void inOrderTread(BTreeNode<T> *node, BTreeNode<T>*& head, BTreeNode<T>*& tail)
{
    if(node != NULL)
    {
        BTreeNode<T>* h = NULL;
        BTreeNode<T>* t = NULL;

        inOrderTread(node->left, h, t);

        node->left = t;

        if(t != NULL)
        {
            t->right = node;
        }

        head = (h != NULL) ? h : node;

        h = NULL;
        t = NULL;

        inOrderTread(node->right, h, t);

        node->right = h;

        if(h != NULL)
        {
            h->left = node;
        }

        tail = (t != NULL) ? t : node;
    }
}

template <typename T>
BTreeNode<T>* inOrderTread2(BTreeNode<T>* node)
{
    BTreeNode<T>* head = NULL;
    BTreeNode<T>* tail = NULL;
    inOrderTread(node, head, tail);

    return head;
}

int main()
{
    BTreeNode<int>* ns = createTree<int>();

    printInOrder(ns);

    cout << endl;

    delOdd2(ns);

    printInOrder(ns);

    cout << endl;

    //如果有指向父节点的指针则需要这样打印节点
    int a[] = {6, 7, 8};

    for(int i = 0; i < 3; i++)
    {
        TreeNode<int>* n = ns + a[i];

        while(n != NULL)
        {
            cout << n->value << " ";

            n = n->parent;
        }

        cout << endl;
    }



    cout << endl;

    ns = inOrderTread2(ns);

    printDualList(ns);

    return 0;
}*/

/*#include <iostream>
#include "MatrixGraph.h"

using namespace std;
using namespace Lib;

int main()
{
    MatrixGraph<3, int, int> g;

    g.setEdge(0, 1, 1);
    g.setEdge(1, 0, 2);
    g.setEdge(1, 2, 3);

    cout << "vCount: " << g.vCount() << endl;
    cout << "eCount: " << g.eCount() << endl;
    cout << "ID(1): " << g.ID(1) << endl;
    cout << "OD(1): " << g.OD(1) << endl;
    cout << "TD(1): " << g.TD(1) << endl;

    cout << "W(0, 1): " << g.getEdge(0, 1) << endl;
    cout << "W(1, 0): " << g.getEdge(1, 0) << endl;
    cout << "W(1, 2): " << g.getEdge(1, 2) << endl;

    SharedPointer< Array<int> > aj = g.getAdjacent(2);
    for(int i = 0; i < aj->length(); i++)
    {
        cout << (*aj)[i] << " ";
    }

    cout << endl;

    cout << "Delete Edge: " << endl;
    g.removeEdge(0, 1);


    cout << "eCount: " << g.eCount() << endl;

    g.setVertex(0, 100);

    cout << "V(0): " << g.getVertex(0) << endl;
    //cout << "W(1, 0): " << g.getEdge(0, 1) << endl;
    return 0;
}*/

/*#include <iostream>
#include "ListGraph.h"

using namespace std;
using namespace Lib;

int main()
{
    ListGraph<char, int> g;

    g.addVertex('A');
    g.addVertex('B');
    g.addVertex('C');
    g.addVertex('D');


    for(int i = 0; i < g.vCount(); i++)
    {
        cout << i << ": " << g.getVertex(i) << endl;
    }

    g.setEdge(0, 1, 5);
    g.setEdge(0, 3, 5);
    g.setEdge(1, 2, 8);
    g.setEdge(2, 3, 2);
    g.setEdge(3, 1, 9);

    cout << "W(0, 1): " << g.getEdge(0, 1) << endl;
    cout << "W(0, 3): " << g.getEdge(0, 3) << endl;
    cout << "W(1, 2): " << g.getEdge(1, 2) << endl;
    cout << "W(2, 3): " << g.getEdge(2, 3) << endl;
    cout << "W(3, 1): " << g.getEdge(3, 1) << endl;


    cout << "eCount: " << g.eCount() << endl;


    //g.removeEdge(3, 1);
    //cout << "W(3, 1): " << g.getEdge(3, 1) << endl;


    cout << "eCount: " << g.eCount() << endl;

    SharedPointer< Array<int> > aj = g.getAdjacent(0);

    for(int i = 0; i < aj->length(); i++)
    {
        cout << (*aj)[i] << endl;
    }

    cout << "ID(1): " << g.ID(1) << endl;
    cout << "OD(1): " << g.OD(1) << endl;
    cout << "TD(1): " << g.TD(1) << endl;
    return 0;
}*/


/*#include <iostream>
#include "MatrixGraph.h"

using namespace std;
using namespace Lib;

int main()
{
    MatrixGraph<9, char, int> g;
    const char* VD = "ABEDCGFHI";
    for(int i = 0; i < 9; i++)
    {
        g.setVertex(0, VD[i]);
    }

    g.setEdge(0, 1, 0);
    g.setEdge(1, 0, 0);

    g.setEdge(0, 3, 0);
    g.setEdge(3, 0, 0);

    g.setEdge(0, 4, 0);
    g.setEdge(4, 0, 0);

    g.setEdge(1, 2, 0);
    g.setEdge(2, 1, 0);

    g.setEdge(1, 4, 0);
    g.setEdge(4, 1, 0);

    g.setEdge(2, 5, 0);
    g.setEdge(5, 2, 0);

    g.setEdge(3, 6, 0);
    g.setEdge(6, 3, 0);

    g.setEdge(6, 4, 0);
    g.setEdge(4, 6, 0);

    g.setEdge(6, 7, 0);
    g.setEdge(7, 6, 0);

    g.setEdge(7, 8, 0);
    g.setEdge(8, 7, 0);

    SharedPointer< Array<int> > sa = g.BFS(0);

    for(int i = 0; i < sa->length(); i++)
    {
        cout << (*sa)[i] << " ";
    }

    cout << endl;

    return 0;
}
*/


/*#include <iostream>
#include "MatrixGraph.h"

using namespace std;
using namespace Lib;

template <typename V, typename E>
//递归深搜函数
void DFS(Graph<V, E>& g, int v, Array<bool>& visited)
{
    if((0 <= v) && (v < g.vCount()))
    {
        cout << v << " ";
        visited[v] = true;

        SharedPointer< Array<int> > aj = g.getAdjacent(v);

        for(int i = 0; i < aj->length(); i++)
        {
            if(!visited[(*aj)[i]])
            {
                DFS(g, (*aj)[i], visited);
            }
        }
    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException, "Invalid v is invalid...");
    }
}

template <typename V, typename E>
void DFS(Graph<V, E>& g, int v)
{
    DynamicArray<bool> visited(g.vCount());

    for(int i = 0; i < visited.length(); i++)
    {
        visited[i] = false;
    }

    DFS(g, v, visited);
}

int main()
{
    MatrixGraph<9, char, int> g;
    const char* VD = "ABEDCGFHI";
    for(int i = 0; i < 9; i++)
    {
        g.setVertex(0, VD[i]);
    }

    g.setEdge(0, 1, 0);
    g.setEdge(1, 0, 0);

    g.setEdge(0, 3, 0);
    g.setEdge(3, 0, 0);

    g.setEdge(0, 4, 0);
    g.setEdge(4, 0, 0);

    g.setEdge(1, 2, 0);
    g.setEdge(2, 1, 0);

    g.setEdge(1, 4, 0);
    g.setEdge(4, 1, 0);

    g.setEdge(2, 5, 0);
    g.setEdge(5, 2, 0);

    g.setEdge(3, 6, 0);
    g.setEdge(6, 3, 0);

    g.setEdge(6, 4, 0);
    g.setEdge(4, 6, 0);

    g.setEdge(6, 7, 0);
    g.setEdge(7, 6, 0);

    g.setEdge(7, 8, 0);
    g.setEdge(8, 7, 0);

    SharedPointer< Array<int> > sa = g.DFS(0);

    for(int i = 0; i < sa->length(); i++)
    {
        cout << (*sa)[i] << " ";
    }

    cout << endl;

    DFS(g, 0);

    return 0;
}*/

















