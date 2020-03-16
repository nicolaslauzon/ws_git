#include <iostream>
#include "Stack.h"
#include "Queue.h"

int main()
{
   Queue<int> *queue;
   queue->push(42);
   queue->push(42);
   SlIterator<int> *iterator(queue->begin());
   iterator->Next();
   std::cout << iterator->getData() << std::endl;
   delete iterator;
   delete queue;
   return 0;
}
