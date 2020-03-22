#include "tokeniser.h"


Tokenizer::Tokenizer(const std::string& input_equation)
{
    is_valid_=false;
    error_message_="no result computed";
    equation_ = input_equation;
}

void Tokenizer::FillList()
{
token_list
}

bool Tokenizer::isValid(std::size_t i)
{
    if ((equation.at(i) >= '0'
        && equation.at(i) <= '9')||
           equation.at(i) == '%' ||
           equation.at(i) == '-' ||
           equation.at(i) == '/' ||
          (equation.at(i) >= '(' &&
           equation.at(i) <= '+')) {
        return true;
    }
    return false;
}
