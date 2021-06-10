#ifndef __MEMDB__
#define __MEMDB__

#include <unordered_map>
#include "./other/memdb_flag.h"
#include "./container/m_string.h"
#include "./container/memdbObject.h"
#include "./container/hash_map.h"
#include "./container/rbtree_map.h"
#include "./container/skiplist.h"
#include "./container/memObject.h"
using namespace std;


class memDB
{
private:
    unordered_map<m_string,memObject> db;
public:
    memDB(/* args */);
    ~memDB();
};







#endif
