#ifndef __MEMOBJECT__
#define __MEMOBJECT__
#include <cstddef>
#include "../other/memdb_flag.h"
#include "memdbObject.h"
#include "hash_map.h"
#include "rbtree_map.h"
#include "skiplist.h"
#include "m_string.h"
struct memObject
{
    int type;
    memdbObject *ptr;
    memObject(int _type,memdbObject* p) {
        type = _type;
        ptr = p;
    }
    ~memObject() {

        switch (type)
        {
        case HASH_TYPE:
            delete dynamic_cast<hash_map<m_string,m_string>*>(ptr);
            break;
        
        case RBTREE_TYPE:
            delete dynamic_cast<rbtree_map<m_string,m_string>*>(ptr);
            break;
        case SKIPLIST_TYPE:
            delete dynamic_cast<skiplist<m_string,m_string>*>(ptr);
            break;
        }
    }
    
};



#endif