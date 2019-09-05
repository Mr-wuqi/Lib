#include "Object.h"
#include <cstdlib>

using namespace std;
namespace Lib
{

//异常规格说明，表示当前的函数不会出现任何异常,保证new失败的时候返回的是一个NULL而不是抛出异常
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
