#ifndef SAMPLER_H
#define SAMPLER_H

#include <iostream>
#include <string>
class Sampler
{
public:
    Sampler(const std::string& input);
    std::string sample();
private:
    std::string equationToSample;
    void removeSpaces();
    void removeExtraChar();
    void removeEqual();
    void addMultiplication();
};

#endif
