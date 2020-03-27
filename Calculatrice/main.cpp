#include "inputoutput.h"
#include "tokeniser.h"
#include "tokensimplifier.h"
#include "tokenvalidity.h"
#include "solver.h"

#include <iostream>
#include <string>
#include <list>
int main ()
{
    // get equation string
    InputOutput inputOutput;
    std::string equation_string = inputOutput.input();
    if (equation_string.size() == 0) {
        std::cerr<< "entered string is empty"<<std::endl;
        return EXIT_FAILURE;
    }

    // get a list of token from the equation
    Tokenizer decode_string(equation_string);
    decode_string.FillList();
    if (decode_string.IsValid() == false) {
        std::cerr << decode_string.ErrorMessage() << std::endl;
        return EXIT_FAILURE;
    }
    std::list<Token> decoded_list = decode_string.Result();

    // Simplify
    TokenSimplifier simplify(decoded_list);

    // Test validity

    TokenValidity validate_equation(simplify.TokenList());
    if (validate_equation.isValid() == false) {
        std::cerr << validate_equation.ErrorMessage() << std::endl;
        return EXIT_FAILURE;
    }

    // Solve the equation with the list as an imput
    Solver solver(simplify.TokenList());
    if (solver.IsValid() == false) {
        std::cerr << solver.ErrorMessage() << std::endl;
        return EXIT_FAILURE;
    }
    int answer = solver.Answer();

    // Output
    inputOutput.output(equation_string, solver.PostFix(), answer);
}
