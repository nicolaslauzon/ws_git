#ifndef TOKENISER_H
#define TOKENISER_H

#include "token.h"

#include <string>
#include <list>

class Tokenizer
{
public:
    Tokenizer(const std::string& input_equation);

    bool IsValid() const { return is_valid_;}
    const std::string& ErrorMessage() const { return error_message_;}
    const std::list<Token>& Result() const { return token_list_;}

private:
    void FillList();
    std::string equation_;
    std::list<Token> token_list_;
    bool isValid(std::size_t i);

    bool is_valid_;
    std::string error_message_;
};

#endif
