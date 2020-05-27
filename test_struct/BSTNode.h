#ifndef BSTNODE_H
#define BSTNODE_H

template <typename T>

class BSTNode {
public:
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;

    BSTNode(const T& data, BSTNode<T>* left = nullptr, BSTNode<T>* right = nullptr) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

#endif // BSTNODE_H
