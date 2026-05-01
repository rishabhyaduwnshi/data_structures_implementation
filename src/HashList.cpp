#include <iostream>
#include "HashList.h"

HashList::HashList()
{
    for (int i = 0; i < TOTAL_HEAD_NODES; i++)
    {
        hash_list[i] = nullptr;
    }
}

void HashList::insert_data(int data)
{
    int row_index = data % TOTAL_HEAD_NODES;

    if (hash_list[row_index] == nullptr)
    {
        Doubly_Node* new_node = new Doubly_Node;
        new_node->data = data;

        hash_list[row_index] = new_node;
        new_node->next_node = new_node;
        new_node->previous_node = new_node;
    }
    else
    {
        Doubly_Node* first_node = hash_list[row_index];
        Doubly_Node* last_node = first_node->previous_node;

        Doubly_Node* new_node = new Doubly_Node;
        new_node->data = data;

        last_node->next_node = new_node;
        new_node->previous_node = last_node;
        new_node->next_node = first_node;
        first_node->previous_node = new_node;
    }
}

void HashList::print_hashlist()
{
    for (int i = 0; i < TOTAL_HEAD_NODES; i++)
    {
        Doubly_Node* head_node = hash_list[i];
        if (head_node != nullptr)
        {
            do
            {
                std::cout << head_node->data << " ";
                head_node = head_node->next_node;
            }
            while (head_node != hash_list[i]);
        }
        std::cout << std::endl;
    }
}
