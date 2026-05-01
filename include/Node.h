#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int data;
    Node* next_node;
};

class Doubly_Node
{
public:
    int data;
    Doubly_Node* next_node;
    Doubly_Node* previous_node;
};

class BinaryTreeNode
{
    public:
        int data;
        BinaryTreeNode* left_child;
        BinaryTreeNode* right_child;
};

#endif