#include <iostream>
#include <string>
#include <algorithm>

#include "b_tree.h"

b_tree_node::b_tree_node(bool leaf) : number_of_keys(0), is_leaf(leaf)
{
    for (int i = 0; i < 2 * t;     ++i) keys[i] = 0;
    for (int i = 0; i < 2 * t + 1; ++i) child_nodes[i] = nullptr;
}

b_tree_node::~b_tree_node(void)
{
    for (int i = 0; i <= number_of_keys; ++i)
        if (child_nodes[i] != nullptr)
            delete child_nodes[i];
}

bool b_tree_node::find(int value)
{
    int i = number_of_keys - 1;
    while (i >= 0 && keys[i] >  value) --i;
    if    (i >= 0 && keys[i] == value) return true;
    if (child_nodes[i + 1] != nullptr) return child_nodes[i + 1]->find(value);
    return false;
}

void b_tree_node::insert_into_node(int value, b_tree_node *node)
{
    keys[number_of_keys] = value;
    child_nodes[number_of_keys + 1] = node;
    int i = number_of_keys;
    while (i > 0 && keys[i] < keys[i - 1])
    {
        std::swap(keys[i - 1], keys[i]);
        std::swap(child_nodes[i], child_nodes[i + 1]);
        --i;
    }
    ++number_of_keys;
}

b_tree_node *b_tree_node::insert(int value, b_tree_node *prev)
{
    if (is_leaf) insert_into_node(value, nullptr);
    else
    {
        int i = number_of_keys - 1;
        while (i >= 0 && keys[i] > value) --i;
        child_nodes[i + 1]->insert(value, this);
    }
    if (number_of_keys == 2 * t) prev = split(this, prev);
    return prev;
}

b_tree_node *b_tree_node::split(b_tree_node *cur, b_tree_node *prev) {
    int median_index = (cur->number_of_keys - 1) / 2;
    int median = cur->keys[median_index];

    b_tree_node *right = new b_tree_node(cur->is_leaf);
    right->child_nodes[0] = cur->child_nodes[median_index + 1];
    cur->child_nodes[median_index + 1] = nullptr;
    cur->keys[median_index] = 0;
    for (int i = median_index + 1; i < cur->number_of_keys; i++) {
        right->insert_into_node(cur->keys[i], cur->child_nodes[i + 1]);
        cur->keys[i] = 0;
        cur->child_nodes[i + 1] = nullptr;
    }
    cur->number_of_keys = median_index;

    if (prev == nullptr) {
        prev = new b_tree_node(false);
        prev->child_nodes[0] = cur;
    }
    prev->insert_into_node(median, right);
    return prev;
}

void b_tree_node::print(int level) 
{
    for(int i = number_of_keys - 1; i >= 0; --i)
    {
        if(child_nodes[i + 1] != nullptr) child_nodes[i + 1]->print(level + 1);
        std::cout << std::string(level, '\t') << keys[i] << "\n"; 
    }
    if (child_nodes[0] != nullptr) child_nodes[0]->print(level + 1);
    return;
}

b_tree::b_tree(void) : root(nullptr), size(0) { }

b_tree::~b_tree(void) 
{ 
    delete root;
}

bool b_tree::find(int value)
{
    if (root != nullptr) return root->find(value);
    return false;
}

void b_tree::insert(int value)
{
    if (root == nullptr) root = new b_tree_node(true);
    ++size;
    b_tree_node *root_candidate = root->insert(value);
    if (root_candidate != nullptr) root = root_candidate;
    return;
}

void b_tree::print(void)
{
    if (root != nullptr) root->print(0);
    return;
}

std::vector<int> ans;

std::vector<int> b_tree::widest_node(void)
{
    if (root == nullptr) return ans;
    root->widest_node();
    return ans;
}

void b_tree_node::widest_node(void)
{
    if (this->number_of_keys > (int)ans.size()) 
    {
        ans.clear();
        for (int i = 0; i < number_of_keys; ++i)
            ans.push_back(keys[i]);
    }
    for (int i = 0; i <= number_of_keys; ++i) 
        if (child_nodes[i] != nullptr)
            child_nodes[i]->widest_node();
}
