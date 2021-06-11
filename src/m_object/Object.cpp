#ifndef __OBJECT_TYPE__
#define __OBJECT_TYPE__

#include <iostream>
using namespace std;
class Object
{

public:
    int type;
    Object()
    {
        std::cout << "构造 object" << std::endl;
    };
    virtual ~Object()
    {
        std::cout << "析构 object" << std::endl;
    };
};
#endif