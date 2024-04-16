#ifndef _QUEUE_H_
#define _QUEUE_H_

struct node
{
    int info;
    struct node *next;
    node(int value) : info(value), next(nullptr) {}
};

class queue
{
public:
    queue(void);
    ~queue(void);
    bool empty(void);
    void enqueue(int data);
    int  dequeue(void);
    void print(void);
    void swap_front_and_back(void);
private:
    node *front;
    node *back;
};

#endif