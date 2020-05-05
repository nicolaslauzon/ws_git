#ifndef PQITERATOR_H
#define PQITERATOR_H

#include "PriorityNode.h"

template <typename T>
class PQIterator {
private:
   PriorityNode<T>* node_;
public:
   PQIterator(PriorityNode<T>* node){
      node_ = node;
   }
   void Iterate(){
      if(node_)
         node_ = node_->next;
   }
   const T& Data() const {
      return node_->data;
   }
};
#endif
