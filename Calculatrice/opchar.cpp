#include "opchar.h"
#include <string>


OpChar::OpChar(std::string value) {
    this-> value = value;
    getType();
    getpriority();
}

int OpChar::getpriority() {
    switch (type) {
    case 1:
        priority = 2;
    case 2:
        priority = 1;
    case 3:case 4:
        priority = 0;
    }
}

void OpChar::getType() {
    switch (value[0]) {
    case '*':case '/':case '%':
        type = 1;
    case '-':case '+':
        type = 2;
    case '(':
        type = 3;
    case ')':
        type = 4;
    default:
        type = 5;

    }
}

inline int OpChar::returnType() {
    return type;
}

inline int OpChar::returnPriority() {
    return priority;
}
