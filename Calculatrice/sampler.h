#ifndef SAMPLER_H
#define SAMPLER_H

#include <iostream>
#include <string>
class Sampler
{
public:
    Sampler(std::string input);
    std::string sample();
private:
    std::size_t size;
    std::string equationToSample;
    void removeSpaces();
    void removeExtraChar();
    void removeEqual();
};

#endif
