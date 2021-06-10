

#include <iostream>
#include <cstring>
#include "container.h"
using namespace std;


int main() {

    //fun();
    unordered_map<string,memObject> db;
    auto a = new SkipList<string,string>(18);

    db["name"] = memObject(STRING_TYPE, a);

    //auto *ss = dynamic_cast<SkipList<string,string>*>(db["name"].ptr);

    a->insert_element("csj","csj");
    a->display_list();

    return 0;
}

