#include <iostream>
#include <fstream>
#include <cstdint>

#include "hash_table_chaining.h"
#include "hash_table_double_hashing.h"

int main(void)
{
    hash_table_chaining t;
    //hash_table_double_hashing t;
    std::ifstream fin("input.txt");
    uint32_t key;
    uint32_t value;
    while (fin >> key >> value)
        t.insert(key, value);
    
    
    t.print();
    std::cout << "################################\n";
    t.remove(2365960);
    t.print();

    //std::cout << t.search(447028681) << "\n";
    if (t.search(447028681) != nullptr) t.search(447028681)->print();

    t.clear();
    std::cout << "\n";
    
    t.print();
    return 0;
}