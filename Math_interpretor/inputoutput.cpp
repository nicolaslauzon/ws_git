#include "inputoutput.h"
#include <string>
#include <iostream>

InputOutput::InputOutput() {

}

std::string InputOutput::input() {
    std::string equation;
    std::cout << "Entrez l'equation souhaite:" << std::endl;
    std::cin >> equation;
    return equation;
}

void InputOutput::output(std::string infix, std::string postfix, size_t result) {
    std::cout <<     "Infix      : " << infix << std::endl <<
                     "Postfix    : " << postfix << std::endl <<
                     "Evaluation : " << result << std::endl;
}




