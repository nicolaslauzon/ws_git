#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>

#include "PriorityNode.h"
#include "SlIterator.h"

template<typename T>

class PriorityQueue{
private:
	PriorityNode<T> *last_;
	std::size_t count_;
public:
   PriorityQueue(){
  		last_ = nullptr;
  		count_ = 0;    
	}

	PriorityQueue & operator=( PriorityQueue& priority_queue) {
     	for(PriorityNode<T>* i = last_; i->next != last_; i = i->next){
       	push(i->Data(), i->Priority(), i->next);
      }
      return *this;
  	} 
	
	~PriorityQueue(){
		while(last_){
     		pop();
    	}
	}

	void push(T data, int priority){
 		if(last_){
 			for(PriorityNode<T>* i = last_->next; i->priority <= priority; i = i->next);
			
      }
		else {
    		last_ = new PriorityNode<T>(data, priority);
     		last_->next = last_;
      }
		++count_;
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
        	++ count_;
    	}
	}


   inline T front(){
 		return last_->next->data;
 	}

   inline int frontPriority(){
   	return last_->next->priority;
   }

   inline size_t size(){
      return count_;
  	}
   inline PQIterator<T>* begin(){
		return last_ ? new PQIterator<T>(last_->next) : nullptr;
  	}
};
#endif

