#include <iostream>
#include "ArrayQueue.h"
using namespace std;
int main() {
ArrayQueue<int> allo(5);
allo.push(42);
allo.push(4289);
allo.push(4289);
allo.push(428987);
    allo.push(428987);
    allo.push(428987);
    allo.push(428987);
    allo.push(428987);allo.push(428987);
    allo.push(428987);
    allo.push(428987);
    allo.push(1);
allo.front();allo.back();
cout << allo.front();
}