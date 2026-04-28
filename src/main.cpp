#include <iostream>
#include "CircularQueue.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    CircularQueue c1;
    c1.insert_node(10);
    c1.insert_node(20);
    c1.insert_node(30);
    c1.insert_node(40);
    c1.insert_node(50);
    c1.print_list();
    c1.delete_node_by_data(10);
    c1.delete_node_by_data(20);
    c1.delete_node_by_data(30);
    c1.delete_node_by_data(40);
    c1.delete_node_by_data(50);
    c1.print_list();
    return 0;
}
