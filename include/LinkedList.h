#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Structure for Linked List
class Node
{
public:
    int data;
    Node* next_node;
};

class LinkedList
{
private:
    Node* head_node;
    Node* tail_node;

public:
    // Constructor
    LinkedList();

    // Insert node at end
    void insert_node(int data);

    // Print list
    void print_list();

    // Delete node by value
    void delete_node_by_data(int data);
};

#endif // LINKEDLIST_H
