#ifndef SLITERATOR_H
#define SLITERATOR_H

#include "SlNode.h"
template <typename T>

class SlIterator {
private:
    SlNode<T>* node_;
public:
    SlIterator(SlNode<T>* node){
        node_ = node;
    }
    void Next() {
         node_ ? node_ = node_->next : node_ = nullptr;
    }
    T getData(){
        return node_ ? node_->data : T();
    }
};
#endif
