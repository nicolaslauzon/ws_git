#ifndef QUEUE_H
#define QUEUE_H

template <typename T>

#include "SlNode.h"
#include <glob.h>

class Queue {
private:
        SlNode<T>*  first,* last;
	size_t count;
	
    public:
	Stack(){
	    first = last = nullptr;
	    count = 0;
	}
	~Stack(){
	    while(first)
		pop();
	}
	void push(const &T data) {
            first = new SlNode<T>(data, first);
            count++;
	}
	void pop(){
	    if (sp){

	    }
	}	    
};
#endif
