#include "ArrayStack.h"

#ifndef BOARD_H
#define BOARD_H
/*!
 *Methods to manipulate the pieces.
 */
class Board {
public:
    Board(int size);
    void moveSmallest();
    void moveOther();
    bool IsFinished();
private:
    ArrayStack<int> board_[3];
    int smallPointer_= 0;
    int height = board_[0].length();
    int direction;
    void BuildTower();
};

#endif