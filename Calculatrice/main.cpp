#include "sampler.h"
#include "inputoutput.h"
#include "validequation.h"
#include "pushstrtoopchar.h"
#include "tokeniser.h"
#include "tokensimplifier.h"
#include "tokenvalidity.h"
#include <iostream>
#include <string>
int main ()
{
 /*   InputOutput inputOutput;
    Sampler sampler(inputOutput.input());
    std::string sampledInput = sampler.sample();
    ValidEquation validEquation(sampledInput);
    validEquation.printError(validEquation.testAll());
    PushStrToOpChar pushStringInQueue(validEquation.returnEquation());
    pushStringInQueue.pushString();*/

    // get equation string
    InputOutput inputOutput;
    std::string equation_string = inputOutput.input();
    if (equation_string.size() == 0) {
        std::cerr<< "entered string is empty"<<std::endl;
        return EXIT_FAILURE;
    }

    // get a list of token from the equation
    Tokenizer decode_string(equation_string);
    if (decode_string.IsValid() == false) {
        std::cerr << decode_string.ErrorMessage() << std::endl;
        return EXIT_FAILURE;
    }
    std::list<Token> decoded_list = decode_string.Result();

    // Simplify
    TokenSimplifier simplify(decoded_list);
    decoded_list = simplify.simplify();

    // Test validity
    TokenValidity validate_equation(decoded_list);
    if (validate_equation.isValid() == false) {
        std::cerr << validate_equation.ErrorMessage() << std::endl;
        return EXIT_FAILURE;
    }

    // Solve the equation with the list as an imput


    // Output

}
