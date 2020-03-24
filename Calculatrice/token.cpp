#include "token.h"

Token::Token()
    : token_type_(kUnknownTokenType)
{

}

Token::Token(const Token &token)
    : token_type_(token.token_type_),
      value_string_(token.value_string_)
{

}

Token Token::BuildFromString(const std::string &string, bool *is_ok)
{
    Token token;
    token.value_string_ = string;
    switch (string[0]) {
        case '*':
            token.token_type_ = kMultiplyTokenType;
            token.priority_ = 2;
            break;
        case '/':
            token.token_type_ = kDivideTokenType;
            token.priority_ = 2;
            break;
        case '%':
            token.token_type_ = kModuloTokenType;
            token.priority_ = 2;
            break;
        case '-':
            token.token_type_ = kMinusTokenType;
            token.priority_ = 1;
            break;
        case '+':
            token.token_type_ = kPlusTokenType;
            token.priority_ = 1;
            break;
        case '(':
            token.token_type_ = kOpenBraceTokenType;
            token.priority_ = 0;
            break;
        case ')':
            token.token_type_ = kCloseBraceTokenType;
            token.priority_ = 0;
            break;
        default:
            token.token_type_ = kUnknownTokenType;
            token.priority_ = 4;
            break;
    }
    if (token.token_type_ == kUnknownTokenType) {
        if (string[0] >= '0' && string[0] <= '9')
            token.token_type_ = kIntTokenType;
    }
    if(!is_ok) {
        if(token.token_type_ == kUnknownTokenType)
            is_ok = new bool(false);
        else
            is_ok = new bool(true);
    }
    return token;
}
