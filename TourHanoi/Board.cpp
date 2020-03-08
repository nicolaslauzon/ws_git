#include "Board.h"
/*!
 *Definition of the board class.
 *This class allow you to manipulate
 *the pieces.
 */
Board::Board(int size)
{
    board_[0].setSize(size); // Initialisation of the desired size
    board_[1].setSize(size);
    board_[2].setSize(size);
    BuildTower();
}
void Board::BuildTower(){ // Test the direction of the first move and create the actual board
    height = board_[0].length();
    if(height%2) // If height is even: direction->left.
        direction = 2;
    else
        direction = 1; // If height is odd: direction->right.
    for (int i = height; i > 0; i--) { // Stack the first tower up.
        board_[0].push(i);
    }
}
void Board::moveSmallest(){ // Move the small piece of value 1.
    board_[((smallPointer_+direction) % 3)].push(1);
    board_[smallPointer_].pop();
    smallPointer_ = (smallPointer_ + direction) % 3;
}
void Board::moveOther(){ // Move the only piece that can be moved other than the smallest.
    for (int i = 0; i < 3;i++) {
        if(board_[i].top()!=1 && board_[i].size())
            for (int j = 0; j < 3;j++) {
                if((board_[i].top() < board_[j].top()) || !(board_[j].size())) {
                    board_[j].push(board_[i].top());
                    board_[i].pop();
                    i = 3;
                    j = 3;
                }
            }
    }
}
bool Board::IsFinished(){ // Test if the third tower is all stacked up.
    if(board_[2].size()==height)
        return false;
    return true;
}
