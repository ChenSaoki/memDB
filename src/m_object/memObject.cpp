#ifndef __MEMOBJECT__
#define __MEMOBJECT__
#include "container.h"
#include <cstddef>

using namespace std;
struct memObject
{
    int type;
    Object *ptr;
    memObject() = default;
    memObject(int _type, Object *p) : type(_type), ptr(p)
    {
        cout<<"cate memobject"<<endl;
    }
    memObject(const memObject& obj):type(obj.type) {
        cout<<"copy memobject"<<endl;
        m_string *a = new m_string("h333333");
        ptr = dynamic_cast<Object*>(a);

    }
    memObject(memObject&& obj):type(obj.type) {
        cout<<"move memobject"<<endl;
        ptr = obj.ptr;
        obj.ptr = nullptr;

    }
    

    ~memObject()
    {
        cout<<"~ memobject"<<endl;
        if (ptr != nullptr) {
            cout<<"ptr != null"<<endl;
            delete ptr;
        }
        
    }
};

#endif