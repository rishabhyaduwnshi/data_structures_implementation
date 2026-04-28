#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
    head_node = nullptr;
    tail_node = nullptr;
}

void LinkedList::insert_node(int data)
{
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next_node = nullptr;

    if (head_node == nullptr)
    {
        head_node = new_node;
        tail_node = new_node;
    }
    else
    {
        tail_node->next_node = new_node;
        tail_node = new_node;
    }
}

void LinkedList::print_list()
{
    if(head_node == nullptr)
    {
        std::cout<<"List is empty\n";
        return;
    }

    Node* current = head_node;

    while (current != nullptr)
    {
        std::cout << current->data << std::endl;
        current = current->next_node;
    }
}

void LinkedList::delete_node_by_data(int data)
{
    if (head_node == nullptr)
        return;

    // Case 1: delete head
    if (head_node->data == data)
    {
        Node* temp = head_node;
        head_node = head_node->next_node;

        if (head_node == nullptr)
            tail_node = nullptr;

        delete temp;
        return;
    }

    Node* previous = head_node;
    Node* current = head_node->next_node;

    while (current != nullptr)
    {
        if (current->data == data)
        {
            previous->next_node = current->next_node;

            if (current == tail_node)
                tail_node = previous;

            delete current;
            return;
        }

        previous = current;
        current = current->next_node;
    }
}
