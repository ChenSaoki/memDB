#include <unordered_map>
#include <string>
#include "memdb.cpp"
struct cmdmode{
    string Cmd;
    int Number;
}

static unordered_map<string,> callback;
callback["add"] = 
