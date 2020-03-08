#include <glob.h>

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
template <typename T>

class ArrayQueue {
	private:
        T* Qs;
        size_t Qp;
        size_t count;
		size_t length_;
	public:
		ArrayQueue(size_t length){
            Qs = new T[length];
            length_ = length;
            Qp = count =  0;
		}
		~ArrayQueue(){
            delete[] Qs;
		}

        void push(const T& var){
            Qs[(Qp+count++)%length_] = var;
		}
        void pop(){
            if(count)
               Qp= (++Qp)%length_;
		}

		inline int size(){
            return length_;
		}
		T front(){
            return Qs[Qp];

        }
		T back(){
            return Qs[(Qp+count)%length_];
		}
};
#endif
