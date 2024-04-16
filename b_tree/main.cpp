#include <iostream>
#include <cstdlib>
#include <ctime>

#include "b_tree.h"

int main(void)
{
    b_tree t;
    srand((unsigned int)time(0));
    for (int i = 0; i < 20; ++i)
        t.insert(rand() % 50);

    std::cout << "####################\n";
    t.print();
    std::cout << "####################\n";
    
    
    for (auto &i : t.widest_node()) std::cout << i << " ";
    std::cout << "\n";

    return 0;
}