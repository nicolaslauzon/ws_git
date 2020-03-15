#ifndef SLITERATOR_H
#define SLITERATOR_H

#include "SlNode.h"
template <typename T>

class SlIterator {
private:
    SlNode<T>* node;
public:
    SlIterator(SlNode<T>* node){
        this->node = node;
    }
    ~SlIterator(){
        delete node;
    }
    void Iterate() {
         node ? node = node->next : node = nullptr;
    }
    T getData(){
        return node ? node->data : T();
    }
};
#endif
