#include <iostream>
#include <string>
#include "Array_Stack.h"
#include "Array_Queue.h"
#include "Methodes.h"

using namespace std;

int main() {
    OnInit();
    infixe_postfixe();
    cout << "Postfix    : ";
    for(int i = 0;i<=Postfixe.size();i=i+1){
        cout << Postfixe.front();
        Postfixe.push(Postfixe.front());
        Postfixe.pop();
    }
    postfixe_resultat();
    cout << "Evaluation : " << resultat << endl;
    return 0;
}
