#ifndef __MEMDB__
#define __MEMDB__
#include "./m_object/container.h"
#include <memory>
using namespace std;

class memdb
{
public:
    unordered_map<string, shared_ptr<Object>> db;

public:
    memdb() = default;
    ~memdb() = default;

    void insert_string(string key, string val);    //插入string，存在即覆盖
    void delete_key(string key);                   //删除db key
    void getStringforkey(string &buf, string key); //获得string
    void insert_skiplist(string key, string score, string member);
    void getElementforSkiplist(string &buf, string key);
    void delElementforSkiplist(string &buf, string key, string score);
    bool isExist(const string &key);
    bool isType(const string &key, int type);
};
bool memdb::isExist(const string &key)
{
    return db.find(key) != db.end();
}

bool memdb::isType(const string &key, int type)
{
    return isExist(key) && db[key]->type == type;
}

void memdb::insert_string(string key, string val) //插入string，存在即覆盖
{
    if (isExist(key))
    {
        db.erase(key);
    }
    db[key] = make_shared<m_string>(val);
    db[key]->type = STRING_TYPE;
}

void memdb::delete_key(string key) //删除db key
{
    if (isExist(key))
    {
        db.erase(key);
    }
}
void memdb::getStringforkey(string &buf, string key)
{
    if (!isExist(key))
    {
        buf = string("null");
        return;
    }
    if (!isType(key, STRING_TYPE))
    {
        buf = string("key is not a string");
        return;
    }
    buf = dynamic_cast<m_string *>(db[key].get())->buf;
}

void memdb::insert_skiplist(string key, string score, string member)
{
    if (isExist(key) && !isType(key, SKIPLIST_TYPE))
    {
        db.erase(key);
    }
    if (!isExist(key))
    {
        db[key] = make_shared<SkipList<string, string>>(18);
        db[key]->type = SKIPLIST_TYPE;
    }
    dynamic_cast<SkipList<string, string> *>(db[key].get())->insert_element(score, member);
}

void memdb::getElementforSkiplist(string &buf, string key)
{
    if (!isExist(key))
    {
        buf = string("null");
        return;
    }
    if (!isType(key, SKIPLIST_TYPE))
    {
        buf = string("key is not a SkipList");
        return;
    }
    auto obj = dynamic_cast<SkipList<string, string> *>(db[key].get());
    obj->display_list(buf);
}

void memdb::delElementforSkiplist(string &buf, string key, string score)
{
    if (!isExist(key))
    {
        buf = string("no find skiplist");
        return;
    }
    if (!isType(key, SKIPLIST_TYPE))
    {
        buf = string("key is not a SkipList");
        return;
    }
    auto obj = dynamic_cast<SkipList<string, string> *>(db[key].get());
    if (obj->search_element(score))
    {
        obj->delete_element(score);
        buf = string("ok!");
        return;
    }
    buf = string("no find element");
}

#endif