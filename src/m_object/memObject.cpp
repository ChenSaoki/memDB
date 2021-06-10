#ifndef __MEMOBJECT__
#define __MEMOBJECT__
#include <cstddef>
#include "container.h"
struct memObject
{
    int type;
    Object *ptr;
    memObject() = default;
    memObject(int _type, Object *p) : type(_type), ptr(p)
    {
    }

    ~memObject()
    {
        if (ptr != nullptr)
            delete ptr;
    }
};

#endif