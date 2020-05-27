#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BSTNode.h"

#include <iostream>

template <typename T>

class BinaryTree
{
private:
    size_t count_;
    BSTNode<T>* root_;

    void Add(const T& data, BSTNode<T>* node);
    void Remove(const T& data, BSTNode<T>* node);
    bool Search(const T& data, BSTNode<T>* node);
public:
    BinaryTree();
    void add(const T& data) {Add(data, root_);}
    void remove(const T& data) {Remove(data, root_);}
    void search(const T& data) {Search(data, root_);}
    size_t size() {return count_;}
};

#endif // BINARYTREE_H
