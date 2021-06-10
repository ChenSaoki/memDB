#ifndef __M_STRING_TYPE__
#define __M_STRING_TYPE__

#include "container.h"

class m_string : public Object
{
public:
    string buf;
public:
    m_string();
    ~m_string();
};

#endif