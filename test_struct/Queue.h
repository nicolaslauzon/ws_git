#ifndef QUEUE_H
#define QUEUE_H
#include "SlNode.h"

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
            if (first==last){
                SlNode<T>* toDelete = last;
                last = last -> next;
                delete toDelete;
            }
            SlNode<T>* toDelete = first;
            first = first -> next;
            delete toDelete;
            count--;
        }
    }
    inline size_t size(){
        return count;
    }
    inline T front(){
        return first->data;

    }
    inline T back(){
        return last->data;
    }
};
#endif
