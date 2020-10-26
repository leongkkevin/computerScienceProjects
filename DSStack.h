//
// Created by Kevin Leong on 10/21/20.
//

#include "DSList.h"

#ifndef INC_20F_FLT_PLN_DSSTACK_H
#define INC_20F_FLT_PLN_DSSTACK_H

template <typename Type>

class DSStack {

private:
    DSList<Type> stackList;

public:
    DSStack();
    DSStack(const DSStack &copy);
    ~DSStack();

    DSStack &operator= (const DSStack &copy);

    void push(Type newItem);
    Type pop();
    void peek();
    bool isEmpty();

    DSList<Type> saveStack();

    int getSize();
    Type top();

    bool searchStack(const Type& inquiry);
};

template<typename Type>
DSStack<Type>::DSStack() = default;

template<typename Type>
DSStack<Type>::DSStack(const DSStack &copy) {

}

template<typename Type>
DSStack<Type>::~DSStack() = default;


template<typename Type>
DSStack<Type> &DSStack<Type>::operator=(const DSStack &copy) {
    copy.stackList = this->stackList;
    return *this;
}

template<typename Type>
void DSStack<Type>::push(Type newItem) {
    this->stackList.push_back(newItem);
}

template<typename Type>
Type DSStack<Type>::pop() {
    if(isEmpty()){
        throw 69;
    } else{
        return this->stackList.pop();
    }
}

template<typename Type>
void DSStack<Type>::peek() {
    return this->stackList.getAt(this->stackList.getSize());
}

template<typename Type>
bool DSStack<Type>::isEmpty() {
    return this->stackList.getSize() <= 0;
}

template<typename Type>
DSList<Type> DSStack<Type>::saveStack() {
    DSList<Type> savedList;

    for(int i = 0; i < this->getSize(); ++i){
        savedList.push_back(this->stackList.getAt(i));
    }

    return savedList;
}


template<typename Type>
int DSStack<Type>::getSize() {
    if(isEmpty()){
        return 0;
    } else {
        return this->stackList.getSize();
    }
}

template<typename Type>
Type DSStack<Type>::top() {
    return this->stackList.getAt(this->stackList.getSize() - 1);
}

template<typename Type>
bool DSStack<Type>::searchStack(const Type& inquiry) {
    bool toReturn;
    for(int i = 0; i < this->stackList.getSize(); ++i){
        if(stackList.getAt(i) == inquiry){
            toReturn = true;
            break;
        } else {
            toReturn = false;
        }
    }

    return toReturn;
}


#endif //INC_20F_FLT_PLN_DSSTACK_H
