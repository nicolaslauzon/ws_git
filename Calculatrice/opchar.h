#ifndef OPCHAR_H
#define OPCHAR_H

#include <string>

enum OpCharType
{
    kMultiplyCharType=1,
    kDivideCharType=2,
    kModuloCharType=3,
    kMinusCharType=4,
    kAddCharType=5,
    kOpenBraceCharType=6,
    kCloseBraceCharType=7,
    kIntCharType=8
};

// New type "Operation Character" to
// manipulate mathematic equation
class OpChar {
    public:
        OpChar();
        OpChar(const std::string& value);
        inline OpCharType returnType();
        inline int returnPriority();
        inline int returnValue();
    private:
        std::string stringEquivalent;
        int priority;
        OpCharType type;
        int value; // Value = "0" if not an integer
        void FillPriorityAndType();
        void getValue();


};

inline OpCharType OpChar::returnType() {
    return type;
}

inline int OpChar::returnPriority() {
    return priority;
}

inline int OpChar::returnValue() {
    return value;
}
#endif
