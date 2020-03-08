#include <iostream>
#include <string>

using namespace std;

template<typename T>

class ArrayStack{
    private: T* ss;                 /*Stack segment*/
             int sp;                /*Stack Pointeur*/
             unsigned int length;   /*Taille du segment de pile*/

public:
        ArrayStack(unsigned int length){        //Constructeur
            this->length = length;
            ss = new T[length];
            sp = 0;                             //Stack pointer
        }

        ~ArrayStack(){                          //Destructeur
            delete[] ss;
        }
                                                // Empiler sur le dessus de la pile
        void push(T data){
            if (sp < length)
                ss[sp++] = data;
        };
                                                // Depiler sur le dessus de la pile
        void pop(){
            if (sp)
                sp--;
        };
                                                // Donnee sur le dessus de la pile
        T top(){
            if (sp)
                return ss[sp - 1];
            return 0;
        };
                                    // Le nombre de donnee dans la pile
        unsigned int size(){
            if (sp)
                return sp;
            return 0;
        };
};