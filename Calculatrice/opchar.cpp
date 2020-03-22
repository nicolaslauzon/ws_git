#include "opchar.h"
#include <string>


OpChar::OpChar()
{
priority=4;
type=kIntCharType;
stringEquivalent='0';
value = 0;
}

OpChar::OpChar(const std::string& value) {
    stringEquivalent = value;
    FillPriorityAndType();
    getValue();
}

void OpChar::FillPriorityAndType()
{
    switch (stringEquivalent.at(0)) {
    case '*':
        type = kMultiplyCharType;
        priority = 2;
        break;
    case '/':
        type = kDivideCharType;
        priority = 2;
        break;
    case '%':
        type = kModuloCharType;
        priority = 2;
        break;
    case '-':
        type = kMinusCharType;
        priority = 1;
        break;
    case '+':
        type = kAddCharType;
        priority = 1;
        break;
    case '(':
        type = kOpenBraceCharType;
        priority = 0;
        break;
    case ')':
        type = kCloseBraceCharType;
        priority = 0;
        break;
    default:
        type = kIntCharType;
        priority = 4;
        break;

    }
}

void OpChar::getValue() {
    (type == 4) ? value = stoi(stringEquivalent) : value = 0;
}
