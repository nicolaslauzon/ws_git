#ifndef SOLVER_H
#define SOLVER_H

#include "token.h"
#include "Queue.h"
#include "Stack.h"

#include <list>



class Solver
{
public:
    Solver(const std::list<Token>& list);
    int Answer() {return answer;}
    bool IsValid() {return is_valid_;}
    std::string ErrorMessage() {return error_message_;}
    std::string PostFix() {return post_fix_;}
private:
    std::list<Token> list_;
    Queue<Token> file_infix_;
    Queue<Token> file_postfix_;
    Stack<Token> pile_operateur_;
    std::string error_message_;
    std::string post_fix_;
    bool is_valid_;
    int answer;

    void PushListInQueue();
    void InfixOpenBrace();
    void InfixCloseBrace();
    void InfixOperator();
    void InfixInteger();
    void InfixEmptyStack();
    void InfixGetPostFix();
    void InfixGetString(Queue<Token>& queue);

    void PostfixStackOperandes();
    void PostFixDoOperation();
    void SolutionFinder();
};

#endif // SOLVER_H
