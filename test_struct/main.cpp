#include <iostream>
#include "Stack.h"
#include "Queue.h"

int main()
{
   Queue<int> *queue;
   queue->push(42);
   queue->push(42);
   SlIterator *iterator(queue->begin());
   delete iterator;
   delete queue;
    return 0;
}
