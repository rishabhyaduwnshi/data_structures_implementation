#ifndef HASHLIST_H
#define HASHLIST_H

#include "Node.h"

#define TOTAL_HEAD_NODES 100

class HashList
{
private:
    Doubly_Node* hash_list[TOTAL_HEAD_NODES];

public:
    HashList();

    void insert_data(int data);

    void print_hashlist();
};

#endif // HASHLIST_H
