//#include "./m_object/container.h"
#include "memdb.cpp"
using namespace std;

int main() {
    memdb db;
    db.insert_string("h1","csj");
    db.insert_string("h2","cqm");
    db.insert_string("h3","hjj");
    db.insert_string("h4","wqh");
    db.insert_string("h1","csjcsjcsjcsj");
    string buf;
    cout<<endl<<buf<<endl<<endl;
    db.getStringforkey(buf,"h1");
    cout<<endl<<buf<<endl<<endl;
    db.delete_key("h2");
    cout<<db.db.size()<<endl;
    return 0;
}