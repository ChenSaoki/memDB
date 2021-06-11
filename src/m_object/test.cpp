
#include "memObject.cpp"
#include <iostream>
#include <cstring>
#include "container.h"
using namespace std;


int main() {

    //fun();
    unordered_map<string,Object*> db;
    
    db["n1"] =new m_string("123");
    db["n1"]->type = STRING_TYPE;
    db["n2"] =new m_string("456");
    db["n2"]->type = STRING_TYPE;
    db["n3"] =new SkipList<string,string>(18);
    db["n3"]->type = SKIPLIST_TYPE;
    dynamic_cast<SkipList<string,string>*>(db["n3"])->insert_element("1","csj");
    dynamic_cast<SkipList<string,string>*>(db["n3"])->insert_element("2","cqm");
    dynamic_cast<SkipList<string,string>*>(db["n3"])->insert_element("3","sqh");
    dynamic_cast<SkipList<string,string>*>(db["n3"])->insert_element("4","hjj");
    //db["n1"] =new m_string("789");
    
    // for(const auto& p : db) {
    //     auto obj = p.second;
    //     switch (obj->type)
    //     {
    //     case STRING_TYPE:
    //         cout<<dynamic_cast<m_string*>(obj)->buf<<endl;
    //         break;
    //     case SKIPLIST_TYPE:
    //         dynamic_cast<SkipList<string,string>*>(obj)->display_list();
    //         break;
    //     }
    // }

    
    return 0;
}

