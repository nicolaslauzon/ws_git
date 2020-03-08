#include <iostream>
#include <string>

using namespace std;

template<typename T>

class ArrayQueue{
    private: T* qs;                 /*Stack segment*/
        size_t qp;                /*Stack Pointeur*/
        size_t length;   /*Taille du segment de pile*/
        size_t count ;
        

public:
    ArrayQueue(size_t length){        //Constructeur
        this->length = length;
        qs = new T[length];
        qp = count = 0;                             //Stack pointer
    }

    ~ArrayQueue(){                          //Destructeur
        delete[] qs;
    }
                                        // Empiler sur le dessus de la pile
    void push(T data){
        if(count<length) {
            qs[(qp + count) % length] = data;
            count = count + 1;
        }
    };
                                        // Depiler sur le dessus de la pile
    void pop(){
            qp = (qp+1) % length;
            count = count-1;
    };
                                        // Donnee sur le dessus de la pile
    T front(){
        if(count) {
            return qs[qp];
        }
        return 0;
    };
    T back(){
        if(count) {
            return qs[(qp+count)%length];
        }
        return 0;
    };
                                        // Le nombre de donnee dans la pile
    inline size_t size(){
            return count;
    };
};
