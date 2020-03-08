#include <iostream>
#include <cmath>
#include "Board.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
/*!
 *Methods that I use to link it all together
 */
using namespace std;

class Functions{
public:
    void onInit(); // Print the title
    int GetTowerLevelCount(); // Ask and return the desired height of tower
    int SolutionFinder(Board& board); // algorithm to find the number of moves
    void answer(int nbrEtages, int nbrMouvements); // Print the answer
};
#endif