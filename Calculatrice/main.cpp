#include "sampler.h"
#include "inputoutput.h"
#include "validequation.h"
#include <iostream>

int main ()
{
    InputOutput inputOutput;
    Sampler sampler(inputOutput.input());
    std::string sampledInput = sampler.sample();
    ValidEquation validEquation(sampledInput);
    validEquation.printError(validEquation.testAll());
}
