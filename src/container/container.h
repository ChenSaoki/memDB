#ifndef CONTAINER
#define CONTAINER

#include <cstddef>
#include "../other/memdb_flag.h"

template<typename k, typename v>
class container
{
public:
    container(/* args */): value_type(CONTAINER){};
    virtual ~container(){};
    container(int level){};
    virtual int insert(k key ,v val) = 0;
    virtual int del(k key) = 0;
    virtual bool search(k key) = 0;
    virtual int update(k key ,v val) = 0;
    virtual void display() = 0;
    virtual size_t size() = 0;
    virtual int type() {return value_type;};
    virtual v getValue(k key);
};

#endif
