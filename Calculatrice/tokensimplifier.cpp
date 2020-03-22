#include "tokensimplifier.h"

TokenSimplifier::TokenSimplifier(const std::list<Token>& token_list)
{
    token_list_ = token_list;
    Simplify();
}

void TokenSimplifier::Simplify()
{
    RemoveRepetition(token_list_);
    AddMultiplication();
}

std::list<Token> TokenSimplifier::RemoveRepetition(const std::list<Token>& token_list)
{
    for (std::list<Token>::const_iterator it = token_list.begin(); it != token_list.end(); ++it) {
        if (it->Type() == 4 || it->Type() == 5){
            it++;
            if (it->Type() == 4 || it->Type() == 5){

            }
        }

    }
}

std::list<Token> TokenSimplifier::AddMultiplication()
{

}
