#ifndef PUSHSTRTOOPCHAR_H
#define PUSHSTRTOOPCHAR_H

#include <string>
#include "opchar.h"
#include "Queue.h"

class PushStrToOpChar
{
public:
    PushStrToOpChar(const std::string& InputEquation);
    const Queue<OpChar>& returnQueue() const;
    void pushString();
private:
    void isBraceOrOperator(std::size_t i);
    std::size_t isNegativeInteger(std::size_t i);
    std::size_t isPositiveInteger(std::size_t i);
    std::string equation;
    Queue<OpChar> queue;
};

#endif
