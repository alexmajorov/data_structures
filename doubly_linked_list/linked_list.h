#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int);
};

class linked_list
{
public:
    linked_list(void);
    ~linked_list(void);
    node *push_front(int);
    node *push_back(int);
    void pop_front(void);
    void pop_back(void);
    node *get(int);
    node *operator [] (int);
    node *insert(int, int);
    void erase(int);
    int find(int);
    void print(void);
    int get_max_index(void);
    int get_min_index(void);
    void remove_between_min_and_max(void);
private:
    node *head;
    node *tail;
};

#endif