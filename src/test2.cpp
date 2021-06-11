//#include "./m_object/container.h"
#include "memdb.cpp"
#include "commandTool.cpp"
using namespace std;

int main() {
    memdb db;
    db.insert_string("n1","csj");
    string res;
    db.getStringforkey(res,"n1");
    cout<<res<<endl;
    return 0;
}