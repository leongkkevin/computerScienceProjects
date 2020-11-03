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
    Type peek();
    bool isEmpty() const;

    DSList<Type> saveStack();

    int getSize() const;
    Type top();

    bool searchStack(const Type& inquiry);
};

template<typename Type>
DSStack<Type>::DSStack() = default;

//Copy Constructor
template<typename Type>
DSStack<Type>::DSStack(const DSStack &copy) {
    for(int i = 0; i < copy.getSize(); ++i){
        this->stackList.push_back(copy.stackList.getAt(i));
    }
}

template<typename Type>
DSStack<Type>::~DSStack() = default;


//Assignment Operator
template<typename Type>
DSStack<Type> &DSStack<Type>::operator=(const DSStack &copy) {
    for(int i = 0; i < copy.getSize(); ++i){
        this->stackList.push_back(copy.stackList.getAt(i));
    }
    return *this;
}

//Pushes the stack
template<typename Type>
void DSStack<Type>::push(Type newItem) {
    this->stackList.push_back(newItem);
}

//Pops the last value from the stack
template<typename Type>
Type DSStack<Type>::pop() {
    if(isEmpty()){
        throw 69;
    } else{
        return this->stackList.pop();
    }
}

//Like pop but doesn't return
template<typename Type>
Type DSStack<Type>::peek() {
    return this->stackList.getAt(this->stackList.getSize() - 1);
}

//Checks the size of the stackList
//Returns true if size is 0
template<typename Type>
bool DSStack<Type>::isEmpty()const {
    return this->stackList.getSize() <= 0;
}

//Saves the stack's current list
//copies into a list and returns it
template<typename Type>
DSList<Type> DSStack<Type>::saveStack() {
    DSList<Type> savedList;

    for(int i = 0; i < this->stackList.getSize(); ++i){
        savedList.push_back(this->stackList.getAt(i));
    }

    return savedList;
}

//Returns size of the list
template<typename Type>
int DSStack<Type>::getSize() const{
    if(isEmpty()){
        return 0;
    } else {
        return this->stackList.getSize();
    }
}

//Returns the top of the stack
template<typename Type>
Type DSStack<Type>::top() {
    return this->stackList.getAt(this->stackList.getSize() - 1);
}

//Iterates through the stackList
//if item is found it returns true
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
