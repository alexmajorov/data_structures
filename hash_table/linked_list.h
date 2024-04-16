#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream>
#include <limits.h>

template <typename T>
class node
{
public:
    T data;
    node *next;
    node *prev;
    node(T data_)
    {
        data = data_;
        next = nullptr;
        prev = nullptr;
    }
    void operator = (T data_)
    {
        data = data_;
    }
};

template <typename T>
class linked_list
{
public:
    linked_list(void)
    {
        head = nullptr;
        tail = nullptr;
    }

    ~linked_list(void) 
    {
        while (head != nullptr) pop_front();
    }

    node<T> *push_front(T data)
    {
        node<T> *ptr = new node<T>(data);
        ptr->next = head;
        if (head != nullptr) head->prev = ptr;
        if (tail == nullptr) tail = ptr;
        head = ptr;
        return ptr;
    }

    node<T> *push_back(T data) 
    {
        node<T> *ptr = new node<T>(data);
        ptr->prev = tail;
        if (tail != nullptr) tail->next = ptr;
        if (head == nullptr) head = ptr;
        tail = ptr;
        return ptr;
    }

    void pop_front(void) 
    {
        if (head == nullptr) return;
        node<T> *ptr = head->next;
        if (ptr != nullptr) ptr->prev = nullptr;
        else tail = nullptr;
        delete head;
        head = ptr;
        return;
    }

    void pop_back(void)
    {
        if (tail == nullptr) return;
        node<T> *ptr = tail->prev;
        if (ptr != nullptr) ptr->next = nullptr;
        else head = nullptr;
        delete tail;
        tail = ptr;
        return;
    }

    node<T> *get(int index) 
    {
        node<T> *ptr = head;
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

    T operator [] (int index) 
    {
        return (get(index))->data;
    }

    node<T> *insert(int index, T data)
    {
        node<T> *right = get(index);
        if (right == nullptr) return push_back(data);

        node<T> *left = right->prev;
        if (left == nullptr) return push_front(data);

        node<T> *ptr = new node<T>(data);

        ptr->prev = left;
        ptr->next = right;
        left->next = ptr;
        right->prev = ptr;

        return ptr;
    }

    void erase(int index) 
    {
        node<T> *ptr = get(index);
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

        node<T> *left = ptr->prev;
        node<T> *right = ptr->next;
        left->next = right;
        right->prev = left;

        delete ptr;
    }

    int find(T value)
    {
        if (head == nullptr) return -1;
        node<T> *current = head;
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

    void print(void)
    {
        node<T> *current = head;

        while (current != nullptr) 
        {
            std::cout << current->data << ", ";
            current = current->next;
        }

        return;
    }

    int get_max_index(void)
    {
        if (head == nullptr) return -1;
        int cur_index = 0;
        int ans_index = 0;
        int tmp = INT_MIN;
        node<T> *current = head;

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

    int get_min_index(void)
    {
        if (head == nullptr) return -1;
        int cur_index = 0;
        int ans_index = 0;
        int tmp = INT_MAX;
        node<T> *current = head;

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

    void remove_between_min_and_max(void)
    {
        int min_index = get_min_index();
        int max_index = get_max_index();

        if (min_index == -1 || max_index == -1) return;

        for (int i = 0; i < abs(max_index - min_index) - 1; ++i)
            erase(std::min(max_index, min_index) + 1);

        return;
    }
private:
    node<T> *head;
    node<T> *tail;
};

#endif