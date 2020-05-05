#ifndef PRIORITYNODE_H
#define PRIORITYNODE_H

#include <iostream>

template <typename T>

class PriorityNode{
public:
    T data;
    size_t priority;
    PriorityNode<T>* next;
    PriorityNode() {
        data = T();
        priority = 0;
        next = nullptr;
    }
    PriorityNode(T data, size_t priority, PriorityNode<T>* next = nullptr) {
        this->data = data;
        this->priority = priority;
        this->next = next;
    }
};
#endif
