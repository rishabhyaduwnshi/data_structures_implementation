#include <iostream>
#include "BinaryTree.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    BinaryTree b1;
    b1.insert_node(10);
    b1.insert_node(20);
    b1.insert_node(30);
    b1.insert_node(40);
    b1.insert_node(50);
    b1.print_inorder();
    return 0;
}
