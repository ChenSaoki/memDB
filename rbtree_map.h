#ifndef RBTREE_MAP
#define RBTREE_MAP

#include <map>
#include <iostream>
#include "container.h"
template<typename k, typename v>
class rbtree_map : public container<k, v> {
private:
    std::map<k,v> obj;
public:
    rbtree_map(/* args */) {};
    int insert(k key ,v val){
        if(obj.count(key) > 0)
            return 0;
        obj.insert(std::pair<k, v>(key, val)); 
        return 1;
    };
    int del(k key) {
        obj.erase(key);
        return 1;
    };
    bool search(k key) {
        return obj.count(key) > 0 ? true: false;
    };
    int update(k key ,v val) {
        if(obj.count(key) < 1) return 0;
        obj[key] = val;
        return 1;
    };
    void display() {
        std::cout<<"display : [";
        for(auto it = obj.begin(); it != obj.end(); it++) {
            std::cout<<'(' <<it->first<<","<<it->second<<')'<<",";
        }
        std::cout<<"]"<<std::endl;
    };
    ~rbtree_map() {

    };

    size_t size() {
        return obj.size();
    };
};
#endif