#include "Functions.h"

void Functions::onInit(){ // Print the title.
    cout << "+---------------------------+"<< endl << "|    Jeu de tour d'Hanoi    |" << endl << "+---------------------------+"<< endl <<endl;
}
int Functions::GetTowerLevelCount() { // Ask the height of the tower desired and return it.
    int height;
    cout << "Nombres d'etages" << endl;
    cin >> height;
    return height;
}
int Functions::SolutionFinder(Board& board){ // algorithm that finds the answer
    int count = 1;
    board.moveSmallest(); // always start by moving the smallest piece (value: 1)
    while(board.IsFinished()){ // test if the 3 tower is completed
        board.moveOther();
        board.moveSmallest(); // It always finish by moving the smallest one
        count+=2;
    }
    return count;
}
void Functions::answer(int nbrEtages, int nbrMouvements){           // Return the height,
    cout << "Nombres d'etages : "<< nbrEtages << endl <<            // the result of the solver,
         "Nombre de mouvements : " << nbrMouvements << endl <<      // and the good answer.
         "Nombre de mouvements prevus : " << pow(2,nbrEtages)-1 << endl;
}

