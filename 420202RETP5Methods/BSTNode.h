#ifndef BSTNODE_H
#define BSTNODE_H

template <typename T>

class BSTNode {
public:
    T data;
    BSTNode(const T& data) {
        this->data = data;
    }
};

#endif // BSTNODE_H
