#ifndef __MEMOBJECT__
#define __MEMOBJECT__
#include <cstddef>
#include "../other/memdb_flag.h"
#include "container.h"
struct memObject
{
    int type;
    Object *ptr;
    memObject(int _type,Object* p):type(_type),ptr(p) { }
    
    ~memObject() {

        switch (type)
        {
        case STRING_TYPE:
            delete dynamic_cast<m_string*>(ptr);
            break;
        case SKIPLIST_TYPE:
            delete dynamic_cast<skiplist<m_string,m_string>*>(ptr);
            break;
        }
    }
    
};



#endif