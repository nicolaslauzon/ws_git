#include "sampler.h"

Sampler::Sampler(std::string input)
{
    equationToSample = input;
    size = equationToSample.size();
}

std::string Sampler::sample()
{
    removeSpaces();
    removeExtraChar();
    removeEqual();
    return equationToSample;
}

void Sampler::removeSpaces()
{
    std::string output;
    std::size_t j = 0;
    for (std::size_t i = 0; i < size; i++) {
        if (equationToSample[i] != ' ') {
            output = output + equationToSample[i];
            j++;
        }
    }
    equationToSample = output;
}

void Sampler::removeExtraChar()
{
    int MinusNum;
    size = equationToSample.size();
    std::string output;
    for (std::size_t i = 0; i < size; i++) {
        MinusNum = 0;
        if (equationToSample[i] == '-' || equationToSample[i] == '+') {
            while(equationToSample[i] == '-' || equationToSample[i] == '+') {
                if (equationToSample[i] == '-')
                    MinusNum++;
                i++;

            }
            if (MinusNum % 2)
                output = output + '-';
            else
                output = output + '+';
            i--;
        }
        else {
        output = output + equationToSample[i];
        }

    }
    equationToSample = output;
}

void Sampler::removeEqual()
{
    int lastChar = size-1;
    if (equationToSample[lastChar]== '=')
        equationToSample.erase(lastChar,lastChar);
}

