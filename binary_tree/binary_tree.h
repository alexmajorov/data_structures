#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

class node 
{
public:
    int data;
    node *left;
    node *right;
    node *parent;
    node(int);
};

class binary_tree
{
public:
    binary_tree(void) : root(nullptr) {}
    ~binary_tree(void);
    void insert(int);
    bool find(int);
    int get_depth(void);
    void print_inorder(void);
    void erase(int);
    void pretty_print(void);
private:
    node *root;
    node *insert_node(node *, int);
    void inorder_traversal(node *);
    void destroy_tree(node *);
    int get_depth_private(node *);
    int find_private(node *, int);
    node *erase_private(node *, int);
    node *min_value_node(node *);
    void pretty_print_private(node *, int);
};

#endif