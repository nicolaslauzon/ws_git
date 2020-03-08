#include <iostream>
#include <string>
#include "Array_Stack.h"
#include "Array_Queue.h"

using namespace std;

ArrayQueue<string> Infixe(25);
ArrayQueue<string> Postfixe(25);
ArrayStack<string> Pile(13);
int resultat = 0;

void OnInit(){/*
    cout <<"Veuillez entrer une equation? " endl;
    cin << << endl;*/
    Infixe.push("1"); //1+2*(5+10)+11
    Infixe.push("+");
    Infixe.push("2");
    Infixe.push("*");
    Infixe.push("(");
    Infixe.push("5");
    Infixe.push("+");
    Infixe.push("10");
    Infixe.push(")");
    Infixe.push("+");
    Infixe.push("11");

    cout << "Infix      : ";
    for(int i = 0;i<Infixe.size();i=i+1){
        cout << Infixe.front();
        Infixe.push(Infixe.front());
        Infixe.pop();
    }
};

bool GetType(string data){
    if((data[0]>47)&&(data[0]<58)){
        return true;
    }
    return false;
}

unsigned char GetPriority(char data){
    switch(data) {
        case '(':
        case ')':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        default:
            return 3;
    }
}

void infixe_postfixe(){
    while(Infixe.size()) {
        if (GetType(Infixe.front())) {
            Postfixe.push(Infixe.front());
            Infixe.pop();
        } else
            switch (GetPriority(Infixe.front()[0])) {
                case 0:
                    if (Infixe.front()[0] == ')') {
                        while (('(' != Pile.top()[0])&&(Pile.top()[0] != 0)) {
                            Postfixe.push(Pile.top());
                            Pile.pop();
                        }
                    } else
                        Pile.push(Infixe.front());
                    break;
                case 1:
                    while ((GetPriority(Pile.top()[0]) >= 1)&&(Pile.top()[0] != 0)) {
                        Postfixe.push(Pile.top());
                        Pile.pop();
                    }
                    break;
                case 2:
                    while ((GetPriority(Pile.top()[0]) == 2)&&(Pile.top()[0] != 0)) {
                        Postfixe.push(Pile.top());
                        Pile.pop();
                    }
                    break;
            }
    }
    Postfixe.push(Pile.top());
    Pile.pop();
}

void postfixe_resultat(){
    while(Postfixe.size()){
        if(GetType(Postfixe.front())) {
            Pile.push(Postfixe.front());
            Postfixe.pop();
        }
        else{
            int variable1 = 0, variable2 = 0, variable3 = 0;
            variable2 = stoi(Pile.top());
            Pile.pop();
            variable1 = stoi(Pile.top());
            Pile.pop();
            switch(Postfixe.front()[0]){
                case '+':
                    variable3 = variable1 + variable2;
                    break;
                case '-':
                    variable3 = variable1 - variable2;
                    break;
                case '*':
                    variable3 = variable1 * variable2;
                    break;
                case '/':
                    variable3 = variable1 / variable2;
                    break;
                case '%':
                    variable3 = variable1 % variable2;
                    break;
            }
            Pile.push(to_string(variable3));
        }
    }
    resultat = stoi(Pile.top());
}