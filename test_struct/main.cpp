#include <iostream>

#include "BSTree.h"

int main()
{
    BSTree<int> tree;
    tree.add(2);
    tree.add(5);
    tree.add(1);
    tree.add(6);
    tree.add(3);
    tree.add(0);
    tree.remove(2);
    return 0;
}
