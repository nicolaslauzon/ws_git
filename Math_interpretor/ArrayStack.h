#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <glob.h>

template <typename T>
class ArrayStack {
private:
    T* ss_;
    size_t sp_;
    size_t length_;

public:
    ArrayStack(size_t length){ // At first the size is not set.
        ss_ = new T[length];
        sp_=0;
        length_= length;
    }
    ~ArrayStack(){
            delete[] ss_;
    }
    void push(const T& var){ // The value "var" is put on top of the stack.
        if (sp_ < length_)
           ss_[sp_++] = var;
    }

    void pop(){ // The value on top of the stack is deleted.
        if (sp_)
            sp_--;
    }


    const T& top() const { // If the stack is empty the return value is undefined. If not it return the top value.
        if(sp_)
            return ss_[sp_-1];
    }
    inline int size(){ // Return the actual size of the stack.
        return sp_;
    }
    inline int length(){ // Return the length of the stack.
        return length_;
    }
};
#endif
