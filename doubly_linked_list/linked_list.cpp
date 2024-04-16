#include <iostream>
#include <limits.h>

#include "linked_list.h" 

node::node(int data_)
{
    data = data_;
    next = nullptr;
    prev = nullptr;
}

linked_list::linked_list(void)
{
    head = nullptr;
    tail = nullptr;
}

linked_list::~linked_list(void) 
{
    while (head != nullptr) pop_front();
}

node *linked_list::push_front(int data)
{
    node *ptr = new node(data);
    ptr->next = head;
    if (head != nullptr) head->prev = ptr;
    if (tail == nullptr) tail = ptr;
    head = ptr;
    return ptr;
}

node *linked_list::push_back(int data) 
{
    node *ptr = new node(data);
    ptr->prev = tail;
    if (tail != nullptr) tail->next = ptr;
    if (head == nullptr) head = ptr;
    tail = ptr;
    return ptr;
}

void linked_list::pop_front(void) 
{
    if (head == nullptr) return;
    node *ptr = head->next;
    if (ptr != nullptr) ptr->prev = nullptr;
    else tail = nullptr;
    delete head;
    head = ptr;
    return;
}

void linked_list::pop_back(void)
{
    if (tail == nullptr) return;
    node *ptr = tail->prev;
    if (ptr != nullptr) ptr->next = nullptr;
    else head = nullptr;
    delete tail;
    tail = ptr;
    return;
}

node *linked_list::get(int index) 
{
    node *ptr = head;
    int n = 0;
    while (n != index) 
    {
        if (ptr == nullptr)
            return ptr;
        ptr = ptr->next;
        n++;
    }
    return ptr;
}

node *linked_list::operator [] (int index) 
{
    return get(index);
}

node *linked_list::insert(int index, int data)
{
    node *right = get(index);
    if (right == nullptr) return push_back(data);

    node *left = right->prev;
    if (left == nullptr) return push_front(data);

    node *ptr = new node(data);

    ptr->prev = left;
    ptr->next = right;
    left->next = ptr;
    right->prev = ptr;

    return ptr;
}

void linked_list::erase(int index) 
{
    node *ptr = get(index);
    if (ptr == nullptr) return;

    if (ptr->prev == nullptr) 
    {
        pop_front();
        return;
    }

    if (ptr->next == nullptr) 
    {
        pop_back();
        return;
    }

    node *left = ptr->prev;
    node *right = ptr->next;
    left->next = right;
    right->prev = left;

    delete ptr;
}

void linked_list::print(void)
{
    node *current = head;

    while (current != nullptr) 
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << "\n";
    return;
}


int linked_list::get_max_index(void)
{
    if (head == nullptr) return -1;
    int cur_index = 0;
    int ans_index = 0;
    int tmp = INT_MIN;
    node *current = head;

    while (current != nullptr) 
    {
        if (tmp < current->data)
        {
            tmp = current->data;
            ans_index = cur_index;
        }
        current = current->next;
        cur_index++;
    }

    return ans_index;
}

int linked_list::get_min_index(void)
{
    if (head == nullptr) return -1;
    int cur_index = 0;
    int ans_index = 0;
    int tmp = INT_MAX;
    node *current = head;

    while (current != nullptr) 
    {
        if (tmp > current->data)
        {
            tmp = current->data;
            ans_index = cur_index;
        }
        current = current->next;
        cur_index++;
    }

    return ans_index;
}
   
void linked_list::remove_between_min_and_max(void)
{
    int min_index = get_min_index();
    int max_index = get_max_index();

    if (min_index == -1 || max_index == -1) return;

    for (int i = 0; i < abs(max_index - min_index) - 1; ++i)
        erase(std::min(max_index, min_index) + 1);

    return;
}

int linked_list::find(int value)
{
    if (head == nullptr) return -1;
    node *current = head;
    int cur_index = 0;

    while (current != nullptr)
    {
        if (current->data == value)
            return cur_index;
        cur_index++;
        current = current->next;
    }
    return -1;
}
