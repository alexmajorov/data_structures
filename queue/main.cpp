#include <iostream>
#include "queue.h"

using std::cout;

int main(void)
{
    queue q;

    cout << "Default queue\n";
    const int arr_len = 10;
    int arr[arr_len] = { 2, 4, 7, 8, 3, 1, 5, 10, 6, 9 };
    for (auto i: arr)
        q.enqueue(i);
    cout << "Old queue: ";
    q.print();
    q.swap_front_and_back();
    cout << "New queue: ";
    q.print();
    cout << "\n";

    cout << "Empty queue\n";
    for (int i = 0; i < arr_len; ++i)
        q.dequeue();
    q.print();
    q.swap_front_and_back();
    cout << "\n";

    cout << "One element queue\n";
    q.enqueue(100);
    cout << "Old queue: ";
    q.print();
    q.swap_front_and_back();
    cout << "New queue: ";
    q.print();
    return 0;
}