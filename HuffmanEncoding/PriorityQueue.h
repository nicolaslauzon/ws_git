#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>

#include "PriorityNode.h"
#include "PQIterator.h"

template<typename T>

class PriorityQueue{
private:
    PriorityNode<T> *qp_;
    size_t count_;
public:
    PriorityQueue(){
        qp_ = nullptr;
        count_ = 0;
    }

    PriorityQueue & operator=( PriorityQueue& priority_queue) {
        for(PriorityNode<T>* i = qp_; i; i = i->next){
            priority_queue.push(i->Data(), i->Priority(), i->next);
        }
        return *this;
    }

    ~PriorityQueue(){
        while(qp_){
            pop();
        }
    }

    void push(T data, size_t priority){
        if(qp_) {
            if (qp_->priority <= priority) {
                PriorityNode<T>* i = qp_;
                while (i->next && i->next->priority <= priority ) {
                    i = i->next;
                }
                i->next = new PriorityNode<T>(data, priority, i->next);
            }
            else {
                qp_ = new PriorityNode<T>(data, priority, qp_);
            }
        }
        else {
             qp_ = new PriorityNode<T>(data, priority);
        }
        ++count_;
    }

    void pop(){
        if (qp_) {
            PriorityNode<T>* to_delete = qp_;
            qp_ = qp_->next;
            delete to_delete;
            --count_;
        }
    }


    inline T front(){
        return qp_->data;
    }

    inline int frontPriority(){
        return qp_->next->priority;
    }

    inline size_t size(){
        return count_;
    }
    inline PQIterator<T>* begin(){
        return new PQIterator<T>(qp_);
    }
};
#endif

