#ifndef _HASH_TABLE_DOUBLE_HASHING_H_
#define _HASH_TABLE_DOUBLE_HASHING_H_

#include <cstdint>
#include "linked_list.h"

const uint32_t GAP = 0xFFFFFFFF;

class hash_table_double_hashing
{
public:
    hash_table_double_hashing(void);
    void insert(uint32_t, uint32_t);
    void remove(uint32_t);
    uint32_t search(uint32_t);
    void print(void);
    void clear(void);
private:
    uint32_t hash1(uint32_t);
    uint32_t hash2(uint32_t);
    static const int capacity = 256;
    uint32_t keys[capacity];
    uint32_t values[capacity]; 
    bool is_occupied[capacity];
    int size = 0;
    int number_of_keys = 0;
};

#endif