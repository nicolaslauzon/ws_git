#ifndef STACK_H
#define STACK_H
#include "SlNode.h"
#include <iostream>
template <typename T>



class Stack {
    private:
        SlNode<T>*  sp_;
        size_t count_;
    public:
        Stack(){
            sp_ = nullptr;
            count_ = 0;
        }
        Stack(const Stack<T>& stack){
            sp_ = stack.sp_;
            count_ = stack.count_;
        }
        ~Stack(){
            while(sp_)
            pop();
        }
        void push(const T& data) {
            sp_ = new SlNode<T>(data, sp_);
            count_++;
        }
        void pop(){
            if (sp_){
                SlNode<T>* toDelete = sp_;
                sp_ = sp_ -> next;
                delete toDelete;
                count_--;
            }
        }
        inline const T& top() const {
            return sp_ ? sp_->data : T();
        }
        inline size_t size(){
            return count_;
        }
};
#endif
