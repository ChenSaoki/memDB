//#include "./m_object/container.h"
#include "memdb.cpp"
#include "commandTool.cpp"
using namespace std;

void get1() {
    cout<<"get1"<<endl;
}

void get2(string& str) {
    str = "get2";
    cout<<"get2"<<endl;
}
union fun{
    void ()() a;
};
int main() {
    fun a1;
    a1.a = &get1
    //a1.a = &get1;
    // unordered_map<string,fun> funs;
    // funs["g1"] = fun();
    // funs["g2"] = fun();
    return 0;
}