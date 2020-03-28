#include "tokenvalidity.h"

TokenValidity::TokenValidity(const std::list<Token>& token_list)
{
    token_list_ = token_list;
    if (testBrace() && testOperator())
        is_valid_ = true;
    else
        is_valid_ = false;
}

bool TokenValidity::testBrace()
{
    int diff = 0;
    for (std::list<Token>::const_iterator i = token_list_.begin(); i != token_list_.end(); ++i) {
        if (i->Type() == kOpenBraceTokenType)
            diff++;
        if (i->Type() == kCloseBraceTokenType)
            diff--;
    }
    if (!diff)
        return true;
    if (diff < 0)
        error_message_ = "The equation you entered is invalid. Unexpected ')'.";
    else {
        error_message_ = "The equation you entered is invalid. Unexpected '('.";
    }
    return false;

}

bool TokenValidity::testOperator()
{
    std::list<Token>::const_iterator i = token_list_.begin(), j = token_list_.begin();
    ++j;
    for (; j != token_list_.end(); ++i , ++j) {
        if (i->Type() == kMultiplyTokenType || i->Type() == kDivideTokenType || i->Type() == kModuloTokenType) {
            if (j->Type() == kMultiplyTokenType || j->Type() == kDivideTokenType || j->Type() == kModuloTokenType) {
                error_message_ = "The equation you  entered is invalid. Unexpected: '" + i->ValueString() + "' or '" + j->ValueString() + "'";
                return false;
            }
        }
    }
    return true;
}
