#include <limits.h>
#include <iostream>
#include "stack.h"

using std::cout;

bool stack::empty(void)
{
    return top == nullptr;
}

stack::~stack(void)
{
    while (!this->empty())
    {
        node* temp = top;
        top = top->next;
        delete temp;
    }
}

void stack::push(int data)
{
    node *new_node = new node(data);
    if (!new_node)
    {
        cout << "Stack overflow\n";
        exit(1);
    }
    new_node->next = top;
    top = new_node;
}

int stack::pop(void)
{
    if (this->empty())
    {
        cout << "Stack is empty. Cannot pop element.\n";
        return INT_MIN;
    }
    node* temp = top;
    int popped = temp->info;
    top = temp->next;
    delete temp;
    return popped;
}

void stack::print(void)
{
    if (this->empty())
    {
        cout << "Stack is empty.\n";
        return;
    }
    node *temp = top;
    while (temp)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << "\n";
    return;
}

stack *stack::upper_half(void)
{
    stack *new_stack = new stack;
    stack *temp = new stack;
    int n = 0, s = 0;
    while (!this->empty())
    {
        int cur = this->pop();
        s += cur; n++;
        temp->push(cur);
    }

    while (!temp->empty())
    {
        int cur = temp->pop();
        this->push(cur);
        if (cur > (s + 0.0) / n)
            new_stack->push(cur);
    }

    delete temp;
    return new_stack;
}