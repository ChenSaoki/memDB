#ifndef __M_STRING__
#define __M_STRING__

#include "memdbObject.h"
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;
class m_string :public memdbObject
{
private:
    int len;
    int end;
    char *str;
public:
    m_string();
    m_string(char *);
    m_string(const string& _str);
    m_string(m_string &&);
    m_string(const m_string &);
    m_string &operator=(m_string &&) = default;
    m_string &operator=(const m_string &) = default;
    ~m_string();
    bool operator < (m_string _str)
    {
        return strcmp(str,_str.str) == 1;
    }
   
    
};
m_string::m_string() {

    end = 0;
    len = 1;
    str = (char*)malloc(sizeof(char));
    *str = '\0';
};
m_string::m_string(char *_str) {

    end = strlen(_str);
    len = end + 5;
    str = (char*)malloc(sizeof(char)*len);
    strcpy(str,_str);
};
m_string::m_string(const string& _str) {

    end = _str.size();
    len = end + 5;
    str = (char*)malloc(sizeof(char)*len);
    strcpy(str,_str.data());
};
m_string::m_string(m_string && _str):len(_str.len),end(_str.end) {
    str = _str.str;
    _str.end = 0;
    _str.str = nullptr;
};
m_string::m_string(const m_string & _str):len(_str.len),end(_str.end) {
    str = (char*)malloc(sizeof(char)*len);
    strcpy(str,_str.str);
};
m_string::~m_string() {
    free(this->str);
};



#endif 