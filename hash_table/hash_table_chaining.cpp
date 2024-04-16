#include <cstdint>
#include <iostream>

#include "hash_table_chaining.h"
#include "linked_list.h"

const uint32_t GAP = 0xFFFFFFFF;

uint32_t hash_table_chaining::hash(uint32_t key)
{
    int s = 0;
    while (key != 0) 
    {
        s += key % 10;
        key = key / 10;
    }
    return s;
}

void hash_table_chaining::insert(uint32_t key, uint32_t value)
{   
    if (key > 0x3B9ACA00) return;
    if (size < capacity)
    {
        uint32_t index = hash(key);
        int keys_index = keys.find(index);
        if (keys_index == -1)
        {
            keys.push_back(index);
            values[number_of_keys].push_back(value);
            ++number_of_keys;
        }
        else values[keys_index].push_back(value);
        ++size;
    }
    return;
}

void hash_table_chaining::print(void)
{
    for (int i = 0; i < number_of_keys; ++i)
        if (keys[i] != GAP)
        {
            std::cout << "[" << keys[i] << ": ";
            values[i].print();
            std::cout << "]\n";
        }
    return;
}

linked_list<uint32_t> *hash_table_chaining::search(uint32_t key)
{
    if (key == GAP) return nullptr;
    int index = keys.find(hash(key));
    if (index != -1) return &values[index];
    return nullptr;
}

void hash_table_chaining::remove(uint32_t key)
{
    int index = keys.find(hash(key));
    if (index == -1) return;
    *(keys.get(index)) = GAP;
    return;
}

void hash_table_chaining::clear(void)
{
    for (int i = 0; i < number_of_keys; ++i) *(keys.get(i)) = GAP;
    return;
}