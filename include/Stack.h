#ifndef STACK_H
#define STACK_H

#include "Node.h"

// Structure for a Stack
class Stack
{
private:
    Doubly_Node* top_node;

public:
    // Constructor
    Stack();

    void push_node(int data);

    void pop_node();

    void print_stack();
};

#endif // STACK_H
