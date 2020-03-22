#ifndef TOKENSIMPLIFIER_H
#define TOKENSIMPLIFIER_H

#include "token.h"

#include <list>



class TokenSimplifier
{
public:
    TokenSimplifier(const std::list<Token>& token_list);

    std::list<Token> TokenList() const {return token_list_;};

private:
    void Simplify();
    std::list<Token> token_list_;
    std::list<Token> RemoveRepetition(const std::list<Token>& token_list);
    std::list<Token> AddMultiplication();
};

#endif // TOKENSIMPLIFIER_H
