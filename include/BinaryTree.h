#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <cstddef>
#include <queue>

#include "Node.h"


class BinaryTree
{
    private:
        BinaryTreeNode* root_node;
        std::queue<BinaryTreeNode*> q;

        void print_inorder(BinaryTreeNode* current_node)
        {
            if(current_node != nullptr)
            {
                print_inorder(current_node->left_child);
                std::cout<<current_node->data<<" ";
                print_inorder(current_node->right_child);
            }
        }

    public:
        BinaryTree()
        {
            root_node = nullptr;
        }

        void insert_node(int data)
        {
            if(root_node == nullptr)
            {
                root_node = new BinaryTreeNode;
                root_node->data = data;
                root_node->left_child = nullptr;
                root_node->right_child = nullptr;
                q.push(root_node);
            }
            else
            {
                BinaryTreeNode* top_node = q.front();
                BinaryTreeNode* new_node = new BinaryTreeNode;
                new_node->data = data;
                new_node->left_child = nullptr;
                new_node->right_child = nullptr;

                if(top_node->left_child == nullptr)
                {
                    top_node->left_child = new_node;
                }
                else
                {
                    top_node->right_child = new_node;
                    q.pop();
                }

                q.push(new_node);
            }

        }

        void print_inorder()
        {
            print_inorder(root_node);
        }
};

#endif
