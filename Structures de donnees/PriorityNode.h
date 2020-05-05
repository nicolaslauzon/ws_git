#ifndef PRIORITYNODE_H
#define PRIORITYNODE_H

template <typename T>

class PriorityNode{
public:
   T data;
	std::size_t priority;
   PriorityNode<T>* next;
	PriorityNode(const T& data, std::size_t priority, PriorityNode<T>* next = nullptr) {
   	this->data = data;
		this->priority = priority;
   	this->next = next;
 	}
};
#endif
