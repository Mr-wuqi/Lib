#include "Object.h"
#include <cstdlib>

using namespace std;
namespace Lib
{

//�쳣���˵������ʾ��ǰ�ĺ�����������κ��쳣,��֤newʧ�ܵ�ʱ�򷵻ص���һ��NULL�������׳��쳣
void* Object::operator new (unsigned int size) throw()
{
    return malloc(size);
}

void Object::operator delete (void* p)
{
    free(p);
}

void* Object::operator new[] (unsigned int size) throw()
{
    return malloc(size);
}
void Object::operator delete[] (void* p)
{
    free(p);
}

bool Object::operator == (const Object& obj)
{
    return (this == &obj);
}

bool Object::operator != (const Object& obj)
{
    return (this != &obj);
}


Object::~Object()
{

}

}
