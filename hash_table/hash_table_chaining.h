#ifndef _HASH_TABLE_CHAINING_H_
#define _HASH_TABLE_CHAINING_H_

#include <cstdint>
#include "linked_list.h"

class hash_table_chaining
{
public:
    void insert(uint32_t, uint32_t);
    void remove(uint32_t);
    linked_list<uint32_t> *search(uint32_t);
    void print(void);
    void clear(void);
private:
    uint32_t hash(uint32_t);
    static const int capacity = 256;
    linked_list<uint32_t> keys;
    linked_list<uint32_t> values[capacity]; 
    int size = 0;
    int number_of_keys = 0;
};

#endif