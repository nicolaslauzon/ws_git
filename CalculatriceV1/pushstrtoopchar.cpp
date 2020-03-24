#include "pushstrtoopchar.h"

PushStrToOpChar::PushStrToOpChar(const std::string& InputEquation)
{
    equation = InputEquation;
}

const Queue<OpChar>& PushStrToOpChar::returnQueue() const
{
    return queue;
}

void PushStrToOpChar::pushString()
{
    for (std::size_t i = 0; i < equation.size();) {
        if (equation.at(i) == '(' || equation.at(i) == ')' || equation.at(i) == '*' || equation.at(i) == '/' || equation.at(i) == '%' || equation.at(i) == '+') {
            isBraceOrOperator(i);
            i++;
        }
        if (equation.at(i) == '-') {
            if (equation.at(i-1) == '*' || equation.at(i-1) == '/' || equation.at(i-1) == '%') {
                i = isNegativeInteger(i);
            }
            else {
                isBraceOrOperator(i);
                i++;
            }
        }
        if(equation.at(i) >= '0' && equation.at(i) <= '9') {
            i = isPositiveInteger(i);
        }
    }
}

void PushStrToOpChar::isBraceOrOperator(std::size_t i)
{
    std::string tmpStr(1, equation.at(i));
    OpChar braceOrOperator(tmpStr);
    queue.push(braceOrOperator);
}

std::size_t PushStrToOpChar::isNegativeInteger(std::size_t i)
{
    std::string str('-',1);
    while (equation.at(++i) >= '0' && equation.at(i) <= '9') {
        str += equation.at(i);
    }
    OpChar negativeInteger(str);
    queue.push(negativeInteger);
    return i;

}

std::size_t PushStrToOpChar::isPositiveInteger(std::size_t i)
{
    std::string str(1, equation.at(i));
        while (equation.at(i++) <= '0' && equation.at(i) >= '9') {
            str += equation.at(i);
        }
    OpChar positiveInteger(str);
    queue.push(positiveInteger);
    return i;
}
