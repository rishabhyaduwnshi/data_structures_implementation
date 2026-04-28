#include <iostream>
#include "CircularQueue.h"

CircularQueue::CircularQueue()
{
    head_node = nullptr;
    tail_node = nullptr;
}

void CircularQueue::insert_node(int data)
{
    if(head_node == nullptr)
    {
        CircularQueueNode* new_node = new CircularQueueNode;
        new_node->data = data;
        new_node->previous_node = new_node;
        new_node->next_node = new_node;

        head_node = new_node;
        tail_node = new_node;
    }
    else
    {
        CircularQueueNode* new_node = new CircularQueueNode;
        new_node->data = data;
        new_node->previous_node = tail_node;
        new_node->next_node = head_node;
        tail_node->next_node = new_node;
        head_node->previous_node = new_node;
        tail_node = new_node;
    }
}

void CircularQueue::delete_node_by_data(int data)
{
    if(head_node == nullptr)
    {
        std::cout<<"List is empty\n";
        return;
    }

    // Iterate through the circular list
    CircularQueueNode* dummy_node = head_node;
    do
    {
        if(dummy_node->data == data)
        {
            // if there is only one node in the list
            if(dummy_node == tail_node && dummy_node->next_node == dummy_node)
            {
                delete dummy_node;
                head_node = nullptr;
                tail_node = nullptr;
                return;
            }
            else
            {
                // Update head if we're deleting the head node
                if(dummy_node == head_node)
                {
                    head_node = dummy_node->next_node;
                }
                
                // Update tail if we're deleting the tail node
                if(dummy_node == tail_node)
                {
                    tail_node = dummy_node->previous_node;
                }
                
                dummy_node->next_node->previous_node = dummy_node->previous_node;
                dummy_node->previous_node->next_node = dummy_node->next_node;
                delete dummy_node;
                return;
            }
        }
        dummy_node = dummy_node->next_node;
    } while(dummy_node != head_node);
}

void CircularQueue::print_list()
{
    if(head_node == nullptr)
    {
        std::cout<<"List is empty\n";
        return;
    }

    CircularQueueNode* dummy_node = head_node;
    while(dummy_node != tail_node)
    {
        std::cout<<dummy_node->data<<std::endl;
        dummy_node = dummy_node->next_node;
    }
    std::cout<<dummy_node->data<<std::endl;
}
