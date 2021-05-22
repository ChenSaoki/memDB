#include <iostream>
#include "./container/memdbObject.h"
#include "./container/hash_map.h"
using namespace std;

class memDB {

private:
    //hash_map<string,memdbObject*> *db = new hash_map<string,memdbObject*>();
public:
    memDB() {
        
    }
    ~memDB() {
        delete db;
    }

    int insert(k key ,v val) {
        cout<<"db insert"<<key<<" "<<val<<endl;
    }
    int del(k key){
        cout<<"db del"<<key<<endl;
    }
    bool search(k key){
        cout<<"db search"<<key<<endl;
    }
    int update(k key ,v val){
        cout<<"db update"<<key<<" "<<val<<endl;
    }
    void display(){
        cout<<"db display"<<endl;
    }
    size_t size() {
        cout<<"db size = "<<db->size()<<endl;
    }
};