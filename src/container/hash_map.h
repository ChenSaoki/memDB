#ifndef HASH_MAP
#define HASH_MAP

#include <unordered_map>
#include <iostream>
#include "memdbObject.h"
template<typename k, typename v>
class hash_map : public memdbObject {
private:
    std::unordered_map<k,v> obj;
    VALUE_TYPE value_type;
public:
    hash_map(/* args */) : value_type(HASH_TYPE) {};
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
        return obj.count(key) > 0 ? true : false;
    };
    int update(k key ,v val) {
        if(obj.count(key) < 1) return 0;
        obj[key] = val;
        return 1;
    };
    v getValue(k key) {
        if(search(key)) {
            return obj[key];
        }
        return NULL;
    }
    void display() {
        std::cout<<"display : [";
        for(auto it = obj.begin(); it != obj.end(); it++) {
            std::cout<<'(' <<it->first<<","<<it->second<<')'<<",";
        }
        std::cout<<"]"<<std::endl;
    };
    ~hash_map() {

    };

    size_t size() {
        return obj.size();
    };

    int type() {
        return value_type;
    };
};
#endif