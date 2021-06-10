#ifndef __M_STRING__
#define __M_STRING__
#include "memdbObject.h"

class m_string : memdbObject
{
public:
    m_string();
    m_string(m_string &&) = default;
    m_string(const m_string &) = default;
    m_string &operator=(m_string &&) = default;
    m_string &operator=(const m_string &) = default;
    ~m_string();

private:
    int len;
    int end;
    char *buf;
};




#endif // !__M_STRING__#define 