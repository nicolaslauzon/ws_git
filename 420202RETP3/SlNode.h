#ifndef SLNODE_H
#define SLNODE_H

template <typename T>

class SlNode{
public:
    T data; // Donnée contenue dans le Node.
    SlNode<T>* next; // Pointeur vers le SlNode suivant.
    SlNode(const T& data,SlNode<T>* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};
#endif
