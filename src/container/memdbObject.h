#ifndef MEMDBOBJECT
#define MEMDBOBJECT

#include <cstddef>
#include "../other/memdb_flag.h"

class memdbObject
{
private:
public:
    memdbObject(){};
    virtual ~memdbObject(){};
    memdbObject(int level){};
    virtual int insert() = 0;
    virtual int del() = 0;
    virtual bool search() = 0;
    virtual int update() = 0;
    virtual void display() = 0;
    virtual size_t size() = 0;
    virtual int type() = 0;
    virtual void getValue() = 0;
};

#endif
