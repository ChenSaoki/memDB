#ifndef __MEMDB__
#define __MEMDB__

#include <unordered_map>
#include "./container/memdbObject.h"
#include "./container/hash_map.h"
#include "./container/rbtree_map.h"
#include "./container/skiplist.h"
using namespace std;

unordered_map<string,memObject> db;
class memDB
{
private:
    
public:
    memDB(/* args */);
    ~memDB();
    int add(const string&,const string);
};

int add(const string& key, const string val) {

}
int get(const string& key) {

}
int del(const string& key) {

}






#endif
