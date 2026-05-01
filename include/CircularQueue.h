#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include "Node.h"

// Structure for Circular Queue

class CircularQueue
{
private:
    Doubly_Node* head_node;
    Doubly_Node* tail_node;

public:
    CircularQueue();

    void insert_node(int data);

    void delete_node_by_data(int data);

    void print_list();
};

#endif // CIRCULARQUEUE_H
