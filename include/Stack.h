#ifndef STACK_H
#define STACK_H

// Structure for a Stack
class Doubly_Node
{
public:
    int data;
    Doubly_Node* next_node;
    Doubly_Node* previous_node;
};

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
