#ifndef QUEUE_H
#define QUEUE_H
#include "SlNode.h"
#include <iostream>

template <typename T>



class Queue {
private:
    SlNode<T>*  first,* last;
	size_t count;
	
    public:
    Queue(){
	    first = last = nullptr;
	    count = 0;
	}
    ~Queue(){
	    while(first)
		pop();
	}
    void push(const T& data) {
        if (first){
            last = last->next = new SlNode<T>(data);
        }
        else
            first = last = new SlNode<T>(data);
            count++;
	}
	void pop(){
        if (first){
            SlNode<T>* toDelete = first;
            first = first->next;
            if (!first)
                last = nullptr;
            delete toDelete;
            count--;
        }
    }
    inline size_t size(){
        return count;
    }
    inline T front(){
        return first ? first->data : T();

    }
    inline T back(){
        return last ? last->data : T();
    }
};
#endif
