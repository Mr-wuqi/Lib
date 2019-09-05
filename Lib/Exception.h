#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "Object.h"

namespace Lib
{

#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))

//纯虚的抽象类
class Exception : public Object
{

protected:
    //同于说明异常的详细信息
    char* m_message;
    //用于说明异常的详细地点
    char* m_location;

    void init(const char* message, const char* file, int line);
public:
    Exception(const char* message);
    Exception(const char* file,int line);
    Exception(const char* message, const char* file, int line);

    Exception(const Exception& obj);
    Exception& operator = (const Exception& obj);

    virtual const char* message() const;
    virtual const char* location() const;

    virtual ~Exception() = 0;
};


class ArithmeticException : public Exception
{
public:
    ArithmeticException() : Exception(0) {}
    ArithmeticException(const char* message) : Exception(message){}
    ArithmeticException(const char *file, int line) : Exception(file,line){}
    ArithmeticException(const char* message, const char *file, int line) : Exception(message,file,line){}

    ArithmeticException(const ArithmeticException& e) : Exception(e) {}
    ArithmeticException& operator = (const ArithmeticException& e)
    {
        Exception::operator =(e);
        return *this;
    }
};

class IndexOutBoundsException : public Exception
{
public:
    IndexOutBoundsException() : Exception(0) {}
    IndexOutBoundsException(const char* message) : Exception(message){}
    IndexOutBoundsException(const char *file, int line) : Exception(file,line){}
    IndexOutBoundsException(const char* message, const char *file, int line) : Exception(message,file,line){}

    IndexOutBoundsException(const IndexOutBoundsException& e) : Exception(e) {}
    IndexOutBoundsException& operator = (const IndexOutBoundsException& e)
    {
        Exception::operator =(e);
        return *this;
    }
};

class NoEnoughMemoryException : public Exception
{
public:
    NoEnoughMemoryException() : Exception(0) {}
    NoEnoughMemoryException(const char* message) : Exception(message){}
    NoEnoughMemoryException(const char *file, int line) : Exception(file,line){}
    NoEnoughMemoryException(const char* message, const char *file, int line) : Exception(message,file,line){}

    NoEnoughMemoryException(const NoEnoughMemoryException& e) : Exception(e) {}
    NoEnoughMemoryException& operator = (const NoEnoughMemoryException& e)
    {
        Exception::operator =(e);
        return *this;
    }
};

class NullPointerException : public Exception
{
public:
    NullPointerException() : Exception(0) {}
    NullPointerException(const char* message) : Exception(message){}
    NullPointerException(const char *file, int line) : Exception(file,line){}
    NullPointerException(const char* message, const char *file, int line) : Exception(message,file,line){}

    NullPointerException(const NullPointerException& e) : Exception(e) {}
    NullPointerException& operator = (const NullPointerException& e)
    {
        Exception::operator =(e);
        return *this;
    }
};

class InvalidParameterException : public Exception
{
public:
    InvalidParameterException() : Exception(0) {}
    InvalidParameterException(const char* message) : Exception(message){}
    InvalidParameterException(const char *file, int line) : Exception(file,line){}
    InvalidParameterException(const char* message, const char *file, int line) : Exception(message,file,line){}

    InvalidParameterException(const InvalidParameterException& e) : Exception(e) {}
    InvalidParameterException& operator = (const InvalidParameterException& e)
    {
        Exception::operator =(e);
        return *this;
    }
};


class InvalidOperationException : public Exception
{
public:
    InvalidOperationException() : Exception(0) {}
    InvalidOperationException(const char* message) : Exception(message){}
    InvalidOperationException(const char *file, int line) : Exception(file,line){}
    InvalidOperationException(const char* message, const char *file, int line) : Exception(message,file,line){}

    InvalidOperationException(const InvalidOperationException& e) : Exception(e) {}
    InvalidOperationException& operator = (const InvalidOperationException& e)
    {
        Exception::operator =(e);
        return *this;
    }
};



}

#endif // EXCEPTION_H
