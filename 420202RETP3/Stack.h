#ifndef STACK_H
#define STACK_H
#include "SlNode.h"
#include <iostream>
#include "SlIterator.h"
template <typename T>



class Stack {
private:
    SlNode<T>*  sp_;
    size_t count_;
public:
    Stack(){
        sp_ = nullptr;
        count_ = 0;
    }
    ~Stack(){
        while(sp_)
        pop();
    }
    void push(const T& data) {
        sp_ = new SlNode<T>(data, sp_);
        count_++;
    }
    void pop(){
        if (sp_){
            SlNode<T>* toDelete = sp_;
            sp_ = sp_ -> next;
            delete toDelete;
            count_--;
        }
    }
    inline T& top(){
        return sp_->data;
    }
    inline size_t size(){
        return count_;
    }
    SlIterator<T> begin(){
        return SlIterator<T>(sp_);
    }
};
#endif
