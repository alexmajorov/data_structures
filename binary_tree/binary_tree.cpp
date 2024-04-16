#include <iostream>

#include "binary_tree.h"

node::node(int data_)
{
    data = data_;
    left = nullptr;
    right = nullptr;
}

binary_tree::~binary_tree(void)
{
    destroy_tree(root);
}

void binary_tree::insert(int value)
{
    root = insert_node(root, value);
    return;
}

int binary_tree::get_depth(void)
{
    return get_depth_private(root);
}

int binary_tree::get_depth_private(node *root_ptr)
{
    if (root_ptr == nullptr)
        return 0;
    else 
    {
        int l_depth = get_depth_private(root_ptr->left);
        int r_depth = get_depth_private(root_ptr->right);
 
        if (l_depth > r_depth)
            return (l_depth + 1);
        else
            return (r_depth + 1);
    }
}

node *binary_tree::insert_node(node *root_ptr, int value) 
{
    if (root_ptr == nullptr) 
    {
        root_ptr = new node(value);
    }
    else if (value <= root_ptr->data) 
    {
        root_ptr->left = insert_node(root_ptr->left, value);
    }
    else 
    {
        root_ptr->right = insert_node(root_ptr->right, value);
    }

    return root_ptr;
}

void binary_tree::inorder_traversal(node *root_ptr)
{
    if (root_ptr != nullptr) 
    {
        inorder_traversal(root_ptr->left);
        std::cout << root_ptr->data << " ";
        inorder_traversal(root_ptr->right);
    }
}

void binary_tree::print_inorder(void)
{
    inorder_traversal(root);
    std::cout << "\n";
}

void binary_tree::pretty_print_private(node *cur, int spaces)
{
    if (cur == nullptr) return;
    spaces += 5;
    pretty_print_private(cur->right, spaces);
    std::cout << "\n";
    for (int i = 5; i < spaces; ++i)
        std::cout << " ";
    std::cout << cur->data << "\n";
    pretty_print_private(cur->left, spaces);
    return;
}

void binary_tree::pretty_print(void)
{
    pretty_print_private(root, 0);
    return;
}

void binary_tree::destroy_tree(node *root_ptr) 
{
    if (root_ptr != nullptr) 
    {
        destroy_tree(root_ptr->left);
        destroy_tree(root_ptr->right);
        delete root_ptr;
    }
    return;
}

bool binary_tree::find(int value)
{
    return find_private(root, value);
}

int binary_tree::find_private(node *root_ptr, int value)
{
    if (root_ptr != nullptr)
    {
        if (root_ptr->data == value) return 1;
        return find_private(root_ptr->left, value) + find_private(root_ptr->right, value);
    }
    return 0;
} 

void binary_tree::erase(int value)
{
    root = erase_private(root, value);
    return;
}

node *binary_tree::erase_private(node *cur, int value)
{
    if      (cur == nullptr)    return cur; 
    if      (value < cur->data) cur->left  = erase_private(cur->left,  value); 
    else if (value > cur->data) cur->right = erase_private(cur->right, value); 
    else if (cur->left != nullptr && cur->right == nullptr)
    {
        cur->data = (min_value_node(cur->right))->data;
        cur->right = erase_private(cur->right, value);
    }
    else if (cur->left  != nullptr) cur = cur->left;   // MEMORY LEAK!!!
    else if (cur->right != nullptr) cur = cur->right;  // MEMORY LEAK!!!
    else cur = nullptr;
    return cur;     
}

node *binary_tree::min_value_node(node *cur) 
{
    while (cur->left != nullptr) cur = cur->left;
    return cur;
} 