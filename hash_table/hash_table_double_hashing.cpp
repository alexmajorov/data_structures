#include <cstdint>
#include <iostream>

#include "hash_table_double_hashing.h"
#include "linked_list.h"

hash_table_double_hashing::hash_table_double_hashing(void)
{
    for (int i = 0; i < capacity; ++i) keys[i] = GAP;
}

uint32_t hash_table_double_hashing::hash1(uint32_t key)
{
    return key % 109;
}

uint32_t hash_table_double_hashing::hash2(uint32_t key)
{
    return 1 + (key % 107);
}

void hash_table_double_hashing::insert(uint32_t key, uint32_t value)
{   
    if (key > 0x3B9ACA00) return;
    if (size < capacity)
    {
        int index = hash1(key);
        int step = hash2(key);

        while (is_occupied[index])
            index = (index + step) % capacity;

        is_occupied[index] = true;
        values[index] = value;
        keys[index] = key;
        ++size;
        ++number_of_keys;
    }
    return;
}

void hash_table_double_hashing::print(void)
{
    for (int i = 0; i < capacity; ++i)
        if (keys[i] != GAP)
        {
            std::cout << "[" << keys[i] << ": " << values[i] << "]\n";   
        }
    return;
}

void hash_table_double_hashing::remove(uint32_t key)
{
    if (key > 0x3B9ACA00) return;
    int index = hash1(key);
    int step = hash2(key);

    while (keys[index] != key)
        index = (index + step) % capacity;

    is_occupied[index] = false;
    keys[index] = GAP;
    --size;
    --number_of_keys;
    return;
}

uint32_t hash_table_double_hashing::search(uint32_t key)
{
    if (key > 0x3B9ACA00) return -1;
    int index = hash1(key);
    int step = hash2(key);

    while (is_occupied[index])
    {
        if (keys[index] == key)
            return values[index];            
        index = (index + step) % capacity;
    }
    return -1;
}

void hash_table_double_hashing::clear(void)
{
    for (int i = 0; i < capacity; ++i) keys[i] = GAP;
    return;
}