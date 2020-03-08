#ifndef OPCHAR_H
#define OPCHAR_H

#include <string>
// New type "Operation Character" to
// manipulate mathematic equation
class OpChar {
    public:
        OpChar(std::string value);
        int type;
        std::string value;
        inline int returnType();
        inline int returnPriority();
    private:
        void getType();
        int getpriority();
        int priority;

};

#endif
