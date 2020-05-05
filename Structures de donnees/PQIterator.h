#ifndef PQITERATOR_H
#define PQITERATOR_H

#include "PriorityNode.h"

template <typename T>
class PQIterator {
private:
   PriorityNode<T>* node_;
//	PriorityNode<T>* first_;
public:
   PQIterator(PriorityNode<T>* node){
    	node_ =/* first_*/ =  node;
   }
   void Iterate(){
   	if(node_)
     		node_ = node_->next;
   }
//	inline bool End() {
//		return node_ != first_;
//	}
  	const T& Data() const {
   	return node_->data;
	}
	const std::size_t Priority() const {
		return node_->priority;
	}
};
#endif
