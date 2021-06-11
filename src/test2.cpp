//#include "./m_object/container.h"
#include "memdb.cpp"
#include "commandTool.cpp"
using namespace std;

int main() {
    vector<string> ref;
    commandTool::Stringsplit("  add   key  val   ",' ',ref);
    for(const auto& str : ref) cout<<str<<endl;
    memdb db;
    db.insert_string("h1","csj");
    
    return 0;
}