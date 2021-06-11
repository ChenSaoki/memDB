#ifndef __MEMDB__
#define __MEMDB__
#include "./m_object/container.h"
using namespace std;

class memdb
{
public:
    unordered_map<string, Object *> db;

public:
    memdb(/* args */);
    ~memdb();

    void insert_string(string key, string val) //插入string，存在即覆盖
    {
        if (db.find(key) != db.end())
        {
            delete db[key];
            db.erase(key);
        }
        db[key] = new m_string(val);
        db[key]->type = STRING_TYPE;
    }

    void delete_key(string key) //删除db key
    {
        if (db.find(key) != db.end())
        {
            delete db[key];
            db.erase(key);
            
        }
    }
    void getStringforkey(string &buf, string key)
    {
        if (db.find(key) == db.end())
        {
            buf = string("null\0");
            //return -1;
            return;
        }
        buf = dynamic_cast<m_string *>(db[key])->buf;
    }
};

memdb::memdb(/* args */)
{
}
memdb::~memdb()
{
    for(const auto& obj : db) {
        delete obj.second;
    }
}

#endif