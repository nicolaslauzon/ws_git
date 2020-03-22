#include "sampler.h"

Sampler::Sampler(const std::string& input)
{
    equationToSample = input;
}

std::string Sampler::sample()
{
    removeSpaces();
    removeExtraChar();
    addMultiplication();
    removeEqual();
    return equationToSample;
}

void Sampler::removeSpaces()
{
    std::string output;
    std::size_t j = 0;
    for (std::size_t i = 0; i < equationToSample.size(); i++) {
        if (equationToSample.at(i) != ' ') {
            output = output + equationToSample.at(i);
            j++;
        }
    }
    equationToSample = output;
}

void Sampler::removeExtraChar()
{
    int MinusNum;
    std::string output;
    for (std::size_t i = 0; i < equationToSample.size(); i++) {
        MinusNum = 0;
        if (equationToSample.at(i) == '-' || equationToSample.at(i) == '+') {
            while(equationToSample.at(i) == '-' || equationToSample.at(i) == '+') {
                if (equationToSample.at(i) == '-')
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
        output = output + equationToSample.at(i);
        }

    }
    equationToSample = output;
}

void Sampler::removeEqual()
{
    int lastChar = equationToSample.size()-1;
    if (equationToSample.at(lastChar)== '=')
        equationToSample.erase(lastChar,lastChar);
}

void Sampler::addMultiplication()
{
    for (std::size_t i = 0; i < equationToSample.size()-1; i++) {
        if (equationToSample.at(i) >= '0' && equationToSample.at(i) <= '9') {
            if (equationToSample.at(i + 1) == '(') {
                equationToSample.insert( ++i, "*");
            }
        }
        if (equationToSample.at(i) == ')') {
            if (equationToSample.at(i + 1) >= '0' && equationToSample.at(i + 1) <= '9') {
                equationToSample.insert( ++i, "*");
            }
        }
    }
}

