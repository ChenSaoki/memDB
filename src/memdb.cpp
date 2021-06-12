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

    void insert_string(string key, string val);    //插入string，存在即覆盖
    void delete_key(string key);                   //删除db key
    void getStringforkey(string &buf, string key); //获得string
    void insert_skiplist(string key, string score, string member);
    void getElementforSkiplist(string &buf, string key);
    void delElementforSkiplist(string &buf, string key, string score);
};

memdb::memdb(/* args */)
{
}
memdb::~memdb()
{
    for (const auto &obj : db)
    {
        delete obj.second;
    }
}

void memdb::insert_string(string key, string val) //插入string，存在即覆盖
{
    if (db.find(key) != db.end())
    {
        delete db[key];
        db.erase(key);
    }
    db[key] = new m_string(val);
    db[key]->type = STRING_TYPE;
}

void memdb::delete_key(string key) //删除db key
{
    if (db.find(key) != db.end())
    {
        delete db[key];
        db.erase(key);
    }
}
void memdb::getStringforkey(string &buf, string key)
{
    if (db.find(key) == db.end())
    {
        buf = string("null\0");
        //return -1;
        return;
    }
    buf = dynamic_cast<m_string *>(db[key])->buf;
}

void memdb::insert_skiplist(string key, string score, string member)
{
    if (db.find(key) != db.end() && db[key]->type != SKIPLIST_TYPE)
    {
        delete db[key];
        db.erase(key);
    }
    if (db.find(key) == db.end())
    {
        db[key] = new SkipList<string, string>(18);
        db[key]->type = SKIPLIST_TYPE;
    }
    dynamic_cast<SkipList<string, string> *>(db[key])->insert_element(score, member);
}

void memdb::getElementforSkiplist(string &buf, string key)
{
    if (db.find(key) == db.end())
    {
        buf = string("null\0");
        return;
    }
    auto obj = dynamic_cast<SkipList<string, string> *>(db[key]);
    obj->display_list(buf);
}

void memdb::delElementforSkiplist(string &buf, string key, string score)
{
    if (db.find(key) == db.end())
    {
        buf = string("no find skiplist!!\0");
        return;
    }
    auto obj = dynamic_cast<SkipList<string, string> *>(db[key]);
    if (obj->search_element(score))
    {
        obj->delete_element(score);
        buf = string("ok!\0");
        return;
    }
    buf = string("no find element!\0");
}

#endif