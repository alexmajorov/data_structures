#ifndef _STACK_H_
#define _STACK_H_

struct node 
{
    int info;
    struct node *next;
    node(int value) : info(value), next(nullptr) {}
};

class stack
{
public:
    stack(void) : top(nullptr) {}
    ~stack(void);
    bool empty(void);
    void push(int);
    int  pop(void);
    void print(void);    
    stack *upper_half(void);
private:
    node *top;
};


#endif