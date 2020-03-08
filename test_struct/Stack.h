#ifndef STACK_H
#define STACK_H
#include "SlNode.h"

template <typename T>



class Stack {
    private:
        SlNode<T>*  sp;
	size_t count;
    public:
	Stack(){
	    sp = nullptr;
	    count = 0;
	}
	~Stack(){
	    while(sp)
		pop();
	}
    void push(const T& data) {
	    sp = new SlNode<T>(data, sp);
	    count++;
	}
	void pop(){
	    if (sp){
	        SlNode<T>* toDelete = sp;
	      	sp = sp -> next;
	    	delete toDelete;
	        count--;
	    }
	}	
    inline const T& top() const {
	    return sp->data;
	}
	inline size_t size(){
	    return count;
	}
};
#endif
