#include "iostream"
#include "stack.h"

using std::cout;

int main(void)
{
    const int arr_len = 10;
    int arr[arr_len] = {2, 4, 7, 8, 3, 1, 5, 10, 6, 9};

    stack old_stack;
    
    for (auto i: arr)
        old_stack.push(i);
    
    cout << "Old stack: ";
    old_stack.print();

    stack *new_stack = old_stack.upper_half();
    
    cout << "New stack: ";
    new_stack->print();

    delete new_stack;
    
    return 0;
}