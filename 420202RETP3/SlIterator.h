#ifndef SLITERATOR_H
#define SLITERATOR_H
#include "SlNode.h"

template <typename T>
class SlIterator {
private:
    SlNode<T>* node_;
public:
    SlIterator(){
        node_ = nullptr;
    }
    SlIterator(const SlIterator& iterator){
        node_ = iterator.node_;
    }
    SlIterator(SlNode<T>* node){
        node_ = node;
    }
    void Iterate(){
        if(node_)
            node_ = node_->next;
    }
    inline bool End(){ //if at the end return "false", if not return "true"
        return  node_ ;
    }
    T& Data() const {
        return node_->data;
    }
};
#endif // SLITERATOR_H