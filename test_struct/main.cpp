#include <iostream>
#include "Stack.h"
#include "Queue.h"

int main()
{
    Queue<int> stack;
    stack.push(12);
    stack.push(12);
    stack.push(1);
    std::cout << stack.front() << std::endl;
    std::cout << stack.back() << std::endl;
    std::cout << stack.size() << std::endl;
    stack.pop();
    stack.pop();
    std::cout << stack.front() << std::endl;
    std::cout << stack.back() << std::endl;
    std::cout << stack.size() << std::endl;

    return 0;
}
