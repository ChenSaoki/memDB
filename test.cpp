#include <iostream>
#include "rbtree_map.h"
#include "hash_map.h"
#include "skiplist.h"
#include <map>
using namespace std;
int main() {
    cout<<"start"<<endl;
    container<int,int> *obj = new hash_map<int,int> ();
     obj->insert(1,1);
     obj->insert(2,2);
     obj->display();
     cout<<obj->size()<<endl;
    cout<<"end"<<endl;
    return 0;
}