#ifndef SLNODE_H
#define SLNODE_H

template <typename T>

class SlNode{
    public:
        T data;
        SlNode<T>* next;
        SlNode(T data,SlNode<T>* next = nullptr) {
            this->data = data;
            this->next = next;
        }
};
#endif
