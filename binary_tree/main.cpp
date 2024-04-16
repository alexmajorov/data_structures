#include <cstdlib>
#include <ctime>
#include <iostream>

#include "binary_tree.h"

int main()
{
    binary_tree tree;
    srand((unsigned int)time(0));
    for (int i = 0; i < 12; ++i)
        tree.insert(rand() % 100 - 50);

    tree.pretty_print();
    std::cout << "Depth: " << tree.get_depth() << "\n";    
    int x;
    std::cout << "Value to find: "; std::cin >> x;
    if (tree.find(x))
        std::cout << x << " is in the tree.\n";
    else
        std::cout << x << " is not in the tree.\n";
    
    /*
    binary_tree tree0;
    tree0.print_inorder();
    std::cout << "Depth: " << tree0.get_depth() << "\n";
    std::cout << "Is 3 found: " << tree0.find(3) << "\n\n";

    binary_tree tree1;

    tree1.insert(5);
    tree1.insert(3);
    tree1.insert(7);
    tree1.insert(1);
    tree1.insert(4);

    tree1.print_inorder();
    std::cout << "Depth: " << tree1.get_depth() << "\n";
    std::cout << "Is 3 found: " << tree1.find(3) << "\n\n";

    binary_tree tree2;

    tree2.insert(1);
    tree2.insert(2);
    tree2.insert(3);
    tree2.insert(4);
    tree2.insert(5);

    tree2.print_inorder();
    std::cout << "Depth: " << tree2.get_depth() << "\n";
    std::cout << "Is 3 found: " << tree2.find(3) << "\n\n";

    binary_tree tree3;

    tree3.insert(10);
    tree3.insert(9);
    tree3.insert(8);
    tree3.insert(7);
    tree3.insert(6);

    tree3.print_inorder();
    std::cout << "Depth: " << tree3.get_depth() << "\n";
    std::cout << "Is 3 found: " << tree3.find(3) << "\n\n";
    */

    return 0;
}
