#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenType
{
    kUnknownTokenType=0,
    kMultiplyTokenType=1,
    kDivideTokenType=2,
    kModuloTokenType=3,
    kMinusTokenType=4,
    kPlusTokenType=5,
    kOpenBraceTokenType=6,
    kCloseBraceTokenType=7,
    kIntTokenType=8

};

class Token
{
public:
    Token();
    Token(const Token& token);

    Token & operator=(const Token& token);

    static Token BuildFromString(const std::string& string,bool *is_ok=nullptr);

    TokenType Type() const { return token_type_;}
    const std::string& ValueString() const { return value_string_;}
private:
    TokenType token_type_;
    std::string value_string_;
};

#endif // TOKEN_H
