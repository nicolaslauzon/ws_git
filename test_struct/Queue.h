#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "SlNode.h"
#include "SlIterator.h"

template<typename T>

class Queue{
private:
    SlNode<T> *last;
    size_t count;
public:
    Queue(){
        last = nullptr;
        count = 0;
    }
    ~Queue(){
        while(last){
            pop();
        }
    }
    void push(T data){
        if(last){
            last->next = new SlNode<T>(data,last->next);
            last=last->next;
        }else {
            last = new SlNode<T>(data);
            last->next = last;
        }
        count++;
    }

    void pop(){
        if (last){
            if(last->next == last){
                delete last;
                last = nullptr;
            }
            else {
                SlNode<T> *todelete = last -> next;
                last -> next = todelete -> next;
                delete todelete;
            }
            count--;
        }
    }


    inline T front(){
        return (last) ? last->next->data : T();
    }

    inline T back(){
        return (last) ? last->data : T();
    }

    inline size_t size(){
        return count;
    }
    SlIterator<T>* begin(){
        if (last)
            return new SlIterator<T>(last->next);
        return nullptr;
    }
};
#endif
