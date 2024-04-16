#ifndef _B_TREE_
#define _B_TREE_

#include <vector>

const int t = 3;

class b_tree_node
{
public:
    b_tree_node(bool);
    ~b_tree_node(void);
    int keys[2 * t];
    int number_of_keys;
private: 
    friend class b_tree;
    b_tree_node *child_nodes[2 * t + 1];
    bool is_leaf;
    bool find(int);
    void insert_into_node(int, b_tree_node *);
    b_tree_node *insert(int, b_tree_node * = nullptr);
    b_tree_node *split(b_tree_node *, b_tree_node *);
    void print(int);
    void widest_node(void);
};

class b_tree
{
public:
    b_tree(void);
    ~b_tree(void);
    bool find(int);
    void insert(int);
    void print(void);
    void clear(void);
    std::vector<int> widest_node(void);
private:
    b_tree_node *root;
    int size;
};

#endif