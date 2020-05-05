#include <iostream>

#include "PriorityQueue.h"

int main()
{
    PriorityQueue<int> queue;
    queue.push(0,1);
    queue.push(1,1);
    queue.push(2,1);
    queue.front();
    queue.~PriorityQueue();
}
