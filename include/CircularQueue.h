#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

// Structure for Circular Queue
class CircularQueueNode
{
public:
    int data;
    CircularQueueNode* next_node;
    CircularQueueNode* previous_node;
};

class CircularQueue
{
private:
    CircularQueueNode* head_node;
    CircularQueueNode* tail_node;

public:
    CircularQueue();

    void insert_node(int data);

    void delete_node_by_data(int data);

    void print_list();
};

#endif // CIRCULARQUEUE_H
