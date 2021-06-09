#ifndef __MEMDBOBJECT__
#define __MEMDBOBJECT__

#include <cstddef>
#include "../other/memdb_flag.h"
#include "./container/memdbObject.h"
#include "./container/hash_map.h"
#include "./container/rbtree_map.h"
#include "./container/skiplist.h"

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
            delete dynamic_cast<hash_map<string,string>*>(ptr);
            break;
        
        case RBTREE_TYPE:
            delete dynamic_cast<rbtree_map<string,string>*>(ptr);
            break;
        case SKIPLIST_TYPE:
            delete dynamic_cast<skiplist<string,string>*>(ptr);
            break;
        }
    }
    
};
class memdbObject
{
private:
public:
    memdbObject(){};
    virtual ~memdbObject(){};
    // memdbObject(int level){};
    // virtual int insert() = 0;
    // virtual int del() = 0;
    // virtual bool search() = 0;
    // virtual int update() = 0;
    // virtual void display() = 0;
    // virtual size_t size() = 0;
    // virtual int type() = 0;
    // virtual void getValue() = 0;
};

#endif
