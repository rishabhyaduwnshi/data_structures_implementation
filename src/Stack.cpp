#include <iostream>
#include "Stack.h"

Stack::Stack()
{
    top_node = nullptr;
}

void Stack::push_node(int data)
{
    if(top_node == nullptr)
    {
        Doubly_Node* new_node = new Doubly_Node;
        new_node->data = data;
        new_node->previous_node = nullptr;
        new_node->next_node = nullptr;
        
        top_node = new_node;
    }
    else
    {
        Doubly_Node* new_node = new Doubly_Node;
        new_node->data = data;
        new_node->previous_node = top_node;
        new_node->next_node = nullptr;

        top_node->next_node = new_node;
        top_node = top_node->next_node;
    }
}

void Stack::pop_node()
{
    if(top_node == nullptr)
    {
        std::cout<<"Stack empty\n";
    }
    else
    {
        Doubly_Node* dummy_node = top_node;
        top_node = top_node->previous_node;

        delete dummy_node;
        dummy_node = nullptr;
    }
}

void Stack::print_stack()
{
    if(top_node == nullptr)
    {
        std::cout<<"Stack empty\n";
    }
    else
    {
        Doubly_Node* dummy_node = top_node;
        while(dummy_node != nullptr)
        {
            std::cout<<dummy_node->data<<std::endl;
            dummy_node = dummy_node->previous_node;
        }
    }
}
