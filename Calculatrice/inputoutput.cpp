#include "inputoutput.h"
#include <string>
#include <iostream>

InputOutput::InputOutput() {

}

std::string InputOutput::input() {
    std::string equation;
    std::cout << "Entrez l'equation souhaitee:" << std::endl;
    std::getline(std::cin, equation);
    return equation;
}

void InputOutput::output(const std::string& infix, const std::string& postfix, int result) {
    std::cout <<     "Infix      : " << infix << std::endl <<
                     "Postfix    : " << postfix << std::endl <<
                     "Evaluation : " << result << std::endl;
}




