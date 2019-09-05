#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Exception.h"


using namespace std;

namespace Lib
{

//构造函数初始化辅助函数
void Exception::init(const char *message, const char *file, int line)
{
    //复制一份异常信息字符串，到堆空间
    m_message = (message ? strdup(message) : NULL);

    if (file !=NULL )
    {
        char sl[16] = {0};
        itoa(line, sl, 10);

        m_location = reinterpret_cast<char*>(malloc(strlen(file) + strlen(sl) + 2));

        //字符串拼接
        if(m_location != NULL)
        {
            m_location = strcpy(m_location, file);
            m_location = strcat(m_location, ":");
            m_location = strcat(m_location, sl);
        }

    }
    else
    {
        m_location = NULL;
    }
}

Exception::Exception(const char* message)
{
    init(message, NULL, 0);
}

Exception::Exception(const char* file,int line)
{
    init(NULL, file, line);
}

Exception::Exception(const char* message, const char* file, int line)
{
    init(message, file, line);
}

Exception::Exception(const Exception& obj)
{
    m_message = strdup(obj.m_message);
    m_location = strdup(obj.m_location);
}

Exception& Exception::operator = (const Exception& obj)
{
    if (this != &obj)
    {
        free(m_message);
        free(m_location);

        m_message = strdup(obj.m_message);
        m_location = strdup(obj.m_location);
    }

    return *this;
}

const char* Exception::message() const
{
    return m_message;
}

const char* Exception::location() const
{
    return m_location;
}

Exception::~Exception()
{
    free(m_message);
    free(m_location);
}

}
