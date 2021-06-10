#ifndef __MEMDB__
#define __MEMDB__

#include <unordered_map>
#include "./other/memdb_flag.h"
#include "./container/memdbObject.h"
#include "./container/hash_map.h"
#include "./container/rbtree_map.h"
#include "./container/skiplist.h"
using namespace std;

unordered_map<m_string,memObject> db;
class memDB
{
private:
    
public:
    memDB(/* args */);
    ~memDB();
    int add(const m_string&,const m_string);
};

int add(const int& type,const m_string& key, const m_string& val) {
    if(type == STRING_TYPE) {
        db[key] = memObject(type,"key");
    } else {
        if(db.count(key) > 1) {
            db.erase(key);
        }
    }
    
}
int get(string& buf, const string& key) {
    if(db.erase(key) > 0) {
        return &db[key];
        return 1;
    }
    return 0;
}
int del(const string& key) {
    if(db.count(key) > 0) {
        db.erase(key);
    }
    return 1;
}






#endif
