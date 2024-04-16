#include <limits.h>
#include <iostream>
#include "queue.h"

using std::cout;

bool queue::empty(void)
{
	return front == nullptr;
}

queue::queue(void)
{
	front = nullptr;
	back  = nullptr;
}

queue::~queue(void)
{
    while (!empty())
    {
        node *temp = front;
        front = front->next;
        delete temp;
    }
}

void queue::enqueue(int value)
{
    node *new_node = new node(value);

    if (empty())
    {
        front = new_node;
        back = new_node;
    }
    else
    {
        back->next = new_node;
        back = new_node;
    }
    return;
}

int queue::dequeue() 
{
    if (empty())
    {
        cout << "Queue is empty\n";
        return INT_MIN;
    }
    node* temp = front;
    int dequeued = temp->info;
    front = front->next;
    if (front == nullptr) back = nullptr;
    delete temp;
    return dequeued;
}

void queue::print(void)
{
    if (empty())
    {
        cout << "Queue is empty.\n";
        return;
    }
    node *temp = front;
    while (temp)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << "\n";
    return;
}

void queue::swap_front_and_back(void)
{
    if (empty())
    {
        cout << "Queue is empty.\n";
        return;
    }
    
    int temp = front->info;
    front->info = back->info;
    back->info = temp;

    return;
}