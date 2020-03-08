#include "Functions.h"
#include "Board.h"
using namespace std;



int main() {
    Functions algo; // the methods that are used to interact with user and find the answer.
    algo.onInit();
    int size = algo.GetTowerLevelCount();
    Board board(size); // Create a tower of hanoi board.
    algo.answer(size, algo.SolutionFinder(board));
    return 0;
}
