#include <glob.h>

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
template <typename T>

class ArrayQueue {
	private:
        T* Qs;
        size_t Qp;
        size_t count_;
		size_t length_;
	public:
		ArrayQueue(size_t length){
            Qs = new T[length];
            length_ = length;
            Qp = count_ =  0;
		}
        ArrayQueue(const ArrayQueue<T>& array_queue){
            length_=array_queue.length_;
            count_=array_queue.count_;
            Qp=0;
            Qs = new T[length_];
            for (int i=0; i<count_; ++i)
                Qs[i]=array_queue.Qs[i];
        }
        ~ArrayQueue(){
            delete[] Qs;
		}

        void push(const T& var){
            if(count_!=length_){
                Qs[(Qp+count_++)%length_] = var;
            }
		}
        void pop(){
            if(count_)
               Qp= (++Qp)%length_;
		}

		inline int size(){
            return length_;
		}
        inline int count(){
            return count_;
        }
        inline bool isEmpty(){
            return count_-Qp;
        }
        inline  const T& front() const {
            return Qs[Qp];

        }
        inline  const T& back() const {
            return Qs[(Qp+count_)%length_];
		}
};
#endif
