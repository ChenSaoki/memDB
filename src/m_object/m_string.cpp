#ifndef __M_STRING_TYPE__
#define __M_STRING_TYPE__

#include "container.h"

class m_string : public Object
{
public:
    string buf;
public:
    m_string();
    m_string(const string&);
    ~m_string();
};

m_string::m_string(/* args */)
{
    cout<<"构造 string"<<endl;
    buf = "";
}

m_string::m_string(const string& str)
{
    cout<<"构造 string="<<str<<endl;
    buf = str;
}

m_string::~m_string()
{
    cout<<"析构 string="<<buf<<"!"<<endl;
}

#endif


