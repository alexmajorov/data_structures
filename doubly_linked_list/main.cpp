#include "iostream"
#include "linked_list.h"
#include <cstdlib>
#include <ctime>

using std::cout;

int main(void)
{
    srand((unsigned int)time(0));
    linked_list l;
    for (int i = 0; i < 20; ++i)
        l.push_back(rand() % 100 - 50);
    cout << "Before: "; l.print();
    l.remove_between_min_and_max();
    cout << " After: "; l.print();
    cout << "Index(3): " << l.find(3);
    cout << "\n";

    /*
    const int arr_len0 = 10;
    int arr0[arr_len0] = { 2, 4, 10, 8, 3, 7, 5, 1, 6, 9 };
    linked_list l0;
    for (auto i: arr0)
        l0.push_back(i);
    cout << "Before: "; l0.print();
    l0.remove_between_min_and_max();
    cout << " After: "; l0.print();
    cout << "Index(3): " << l0.find(3);
    cout << "\n";

    const int arr_len1 = 10;
    int arr1[arr_len1] = { 2, 4, 1, 8, 3, 7, 5, 10, 6, 9 };
    linked_list l1;
    for (auto i: arr1)
        l1.push_back(i);
    cout << "Before: "; l1.print();
    l1.remove_between_min_and_max();
    cout << " After: "; l1.print();
    cout << "Index(3): " << l1.find(3);
    cout << "\n";

    const int arr_len2 = 2;
    int arr2[arr_len2] = { 1, 10 };
    linked_list l2;
    for (auto i: arr2)
        l2.push_back(i);
    cout << "Before: "; l2.print();
    l2.remove_between_min_and_max();
    cout << " After: "; l2.print();
    cout << "Index(3): " << l2.find(3);
    cout << "\n";

    const int arr_len3 = 3;
    int arr3[arr_len3] = { 1, 2, 3 };
    linked_list l3;
    for (auto i: arr3)
        l3.push_back(i);
    cout << "Before: "; l3.print();
    l3.remove_between_min_and_max();
    cout << " After: "; l3.print();
    cout << "Index(3): " << l3.find(3);
    cout << "\n";

    const int arr_len4 = 5;
    int arr4[arr_len4] = { 2, 2, 2, 2, 2 };
    linked_list l4;
    for (auto i: arr4)
        l4.push_back(i);
    cout << "Before: "; l4.print();
    l4.remove_between_min_and_max();
    cout << " After: "; l4.print();
    cout << "Index(3): " << l4.find(3);
    cout << "\n";

    const int arr_len5 = 6;
    int arr5[arr_len5] = { 1, 1, 1, 3, 3, 3 };
    linked_list l5;
    for (auto i: arr5)
        l5.push_back(i);
    cout << "Before: "; l5.print();
    l5.remove_between_min_and_max();
    cout << " After: "; l5.print();
    cout << "Index(3): " << l5.find(3);
    cout << "\n";

    linked_list l6;
    cout << "Before: "; l6.print();
    l6.remove_between_min_and_max();
    cout << " After: "; l6.print();
    cout << "Index(3): " << l6.find(3);
    cout << "\n";
    
    */
    return 0;
}