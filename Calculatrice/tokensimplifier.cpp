#include "tokensimplifier.h"

TokenSimplifier::TokenSimplifier(const std::list<Token>& token_list)
{
    token_list_ = token_list;
    Simplify();
}

void TokenSimplifier::Simplify()
{
    token_list_ = RemoveRepetition(token_list_);
    AddMultiplication();
}

std::list<Token> TokenSimplifier::RemoveRepetition(const std::list<Token>& token_list)
{
    std::list<Token> simplified_list;
    std::list<Token>::const_iterator i = token_list.begin();
    std::list<Token>::const_iterator j = token_list.begin();
    ++j;
    while (i != token_list.end()) {
        // case of '-' and '-': convert to '+'
        if (i->Type() == kMinusTokenType && j->Type() == kMinusTokenType) {
            simplified_list.push_back(Token::BuildFromString("+"));
            ++i;
            ++j;
        }
        // case of '+' and '+': convert to '+'
        else if (i->Type() == kPlusTokenType && j->Type() == kPlusTokenType) {
            simplified_list.push_back(Token::BuildFromString("+"));
            ++i;
            ++j;
        }
        // case of '+' and '-', or '-' and '+': convert to '-'
        else if ((i->Type() == kMinusTokenType && j->Type() == kPlusTokenType) ||
                 (i->Type() == kPlusTokenType && j->Type() == kMinusTokenType)) {
            simplified_list.push_back(Token::BuildFromString("-"));
            ++i;
            ++j;
        }
        // something else, just keep it
        else {
            simplified_list.push_back(*i);
        }
        ++i;
        ++j;
    }
    if (simplified_list.size() != token_list.size())
        simplified_list = RemoveRepetition(simplified_list);
    return simplified_list;
}

void TokenSimplifier::AddMultiplication()
{
    std::list<Token>::const_iterator i = token_list_.begin(), j = token_list_.begin();
    ++j;
    for (; j != token_list_.end(); ++i , ++j) {
        if (i->Type() == kIntTokenType) {
            if (j->Type() == kOpenBraceTokenType) {
                token_list_.insert(++i, Token::BuildFromString("*"));
                ++j;
            }
        }
        if (i->Type() == kCloseBraceTokenType) {
            if (j->Type() == kIntTokenType) {
                token_list_.insert( ++i, Token::BuildFromString("*"));
                ++j;
            }
        }
    }
}
