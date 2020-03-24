#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "SlNode.h"
#include "SlIterator.h"

template<typename T>

class Queue{
private:
    SlNode<T> *last_;
    size_t count_;
public:
    Queue(){
        last_ = nullptr;
        count_ = 0;
    }
    Queue (const Queue<T>& queue) {
        last_ = queue.last_;
        count_ = queue.count_;
    }
    ~Queue(){
        while(last_){
            pop();
        }
    }
    void push(T data){
        if(last_){
            last_->next = new SlNode<T>(data,last_->next);
            last_=last_->next;
        }else {
            last_ = new SlNode<T>(data);
            last_->next = last_;
        }
        count_++;
    }

    void pop(){
        if (last_){
            if(last_->next == last_){
                delete last_;
                last_ = nullptr;
            }
            else {
                SlNode<T> *todelete = last_ -> next;
                last_ -> next = todelete -> next;
                delete todelete;
            }
            count_--;
        }
    }


    inline T front(){
        return (last_) ? last_->next->data : T();
    }

    inline T back(){
        return (last_) ? last_->data : T();
    }

    inline size_t size(){
        return count_;
    }
    SlIterator<T>* begin(){
        if (last_)
            return new SlIterator<T>(last_->next);
        return nullptr;
    }
};
#endif
