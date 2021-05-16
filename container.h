#ifndef CONTAINER
#define CONTAINER

#include <cstddef>
template<typename k, typename v>
class container
{
public:
    container(/* args */){};
    container(int level){};
    virtual int insert(k key ,v val) = 0;
    virtual int del(k key) = 0;
    virtual bool search(k key) = 0;
    virtual int update(k key ,v val) = 0;
    virtual void display() = 0;
    virtual size_t size() = 0;
    virtual ~container(){};
};

#endif
