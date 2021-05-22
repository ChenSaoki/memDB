#ifndef MEMDBFLAG
#define MEMDBFLAG
enum VALUE_TYPE {
    OBJECT           = 0,
    INT_TYPE         = 1,
    LONG_TYPE        = 2,
    STRING_TYPE      = 4,
    HASH_TYPE        = 8,
    RBTREE_TYPE      = 16,
    SKIPLIST_TYPE    = 32
};
#endif