//
// Created by Kevin Leong on 10/21/20.
//

#include <iostream>

using namespace std;

#ifndef INC_20F_FLT_PLN_DSLIST_H
#define INC_20F_FLT_PLN_DSLIST_H

template <typename Type>

//NODE CLASS
class DSNode {
private:

public:
    Type payload;
    DSNode* next;
    DSNode* previous;

    DSNode(){
        next = nullptr;
        previous = nullptr;
    }

    DSNode(Type payload) {
        this->payload = payload;
        next = previous = nullptr;
    }

    ~DSNode()= default;

    DSNode(const DSNode<Type> & copy){
        this->payload = copy.payload;
        this->next = copy.next;
        this->previous = copy.previous;
    }

    DSNode &operator=(const DSNode<Type> & copy) {
        this->payload = copy.payload;
        this->next = copy.next;
        this->previous = copy.previous;

        return *this;
    }
};


template <typename Type>

class DSList {
private:
    DSNode<Type>* head;
    DSNode<Type>* tail;
    int size;
public:
    //Constructors
    DSList(){
        head = tail = nullptr;;
        size = 0;
    }

    //Rule of Three
    ~DSList(){
        if(head!= nullptr) {
            DSNode<Type> *temp = head;
            DSNode<Type> *tempNext = temp ->next;
            for (int i = 0; i < size; i++) {
                delete temp;
                temp = tempNext;
                if(temp != nullptr){
                    tempNext = temp->next;
                }
            }
        }
    }

    DSList(const DSList& copy){
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;

        DSNode<Type>* temp = copy.head;
        for(int i = 0; i < copy.size; i++){
            push_back(temp->payload);
            temp = temp->next;
        }

        delete temp;
    }

    DSList &operator=(const DSList &copy) {
        if (this != &copy) {
            if(this->head != nullptr){
                DSNode<Type> *temp = head;
                DSNode<Type> *tempNext = temp ->next;
                for (int i = 0; i < size; i++) {
                    delete temp;
                    temp = tempNext;
                    if(temp != nullptr){
                        tempNext = temp->next;
                    }
                }
            }

            this->head = nullptr;
            this->tail = nullptr;
            this->size = 0;

            DSNode<Type>* temp = copy.head;
            for(int i = 0; i < copy.size; i++){
                push_back(temp->payload);
                temp = temp->next;
            }
            //delete temp;
        }

        return *this;
    }


    //insert and remove functons
    void push_back(Type data){
        if(this->head == nullptr){
            this->head = new DSNode<Type>(data);
            this->tail = this->head;
            this->size++;
        } else{
            tail->next = new DSNode<Type>(data);
            tail->next->previous = tail;
            tail = tail->next;
            size++;
        }
    }

    //removes something by data type
    void remove(Type data){
        size--;
        DSNode<Type>* temp;
        if(head->payload == data){
            temp = head;
            temp->next->previous = nullptr;
            head = temp->next;
            delete temp;
        } else
        if(tail->payload == data){
            temp = tail;
            temp->previous->next = nullptr;
            tail = temp->previous;
            delete temp;
        } else {
            temp = head;
            while (temp != nullptr) {
                if (temp->payload == data) {
                    temp->previous->next = temp->next;
                    temp->next->previous = temp->previous;
                    delete temp;
                }
                temp = temp->next;
            }
        }
    }
//
//    //removes something at an index
    void removeAt(int index){
        DSNode<Type>* temp = head;
        if(index == 0){
            temp->next->previous = nullptr;
            head = temp->next;
            delete temp;

        } else
        if(index == size){
            temp = tail;
            temp->previous->next = nullptr;
            tail = temp->previous;
            delete temp;

        } else {
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            delete temp;
        }

        size--;
    }

    //removes the first and returns that value
    Type pop(){
        Type toReturn;
        DSNode<Type>* temp = tail;

        if(this->size == 1){
            tail = head = nullptr;
        } else {
            tail = temp->previous;
            tail->next = nullptr;
        }

        toReturn = temp->payload;
        delete temp;
        this->size--;

        return toReturn;
    }

    //access methods
    Type& getAt(int index) const{
        DSNode<Type>* temp = this->head;
        for(int i = 0; i < index; ++i){
            temp = temp->next;
        }
        return temp->payload;
    }

    //searches list for item
    int search(const Type &searchItem) const{
        for(int i = 0; i < this->size; ++i){
            if(this->getAt(i) == searchItem){
                return i;
            }
        }

        return -1;
    }

    //returns the size
    int getSize() const{
        return size;
    }

};


#endif //INC_20F_FLT_PLN_DSLIST_H
