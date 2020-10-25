//
// Created by Kevin Leong on 10/21/20.
//

#include "DSList.h"
#include "Flight.h"

#ifndef INC_20F_FLT_PLN_DSADJLIST_H
#define INC_20F_FLT_PLN_DSADJLIST_H

template <typename Type>

class DSAdjList {
private:
    DSList<DSList<Type>> list;

public:
    DSAdjList<Type>();
    DSAdjList<Type> (Type head);

    int find(Type search);

    void addToListNum(int listNum, Type data);
    void addToListName(const Type &listName, Type data);
    void addList(DSList<Type> newList);
    void add(Type data);

    int listSize(int position);
    int totalSize();

    Type atNum(int listNum, int index);
    Type atName(Type listName, int index);

};

template<typename Type>
DSAdjList<Type>::DSAdjList() {
}

template<typename Type>
DSAdjList<Type>::DSAdjList(Type head) {
    DSList<Type> newList;
    newList.push_back(head);
    this->list.push_back(newList);
}

template<typename Type>
int DSAdjList<Type>::find(Type search) {
    for(int i = 0; i < this->list.getSize(); ++i){
        if(this->list.getAt(i).getAt(0) == search){
            return i;
        }
    }
    return -1;
}

template<typename Type>
void DSAdjList<Type>::addList(DSList<Type> newList) {
    this->list.push_back(newList);
}

template<typename Type>
void DSAdjList<Type>::addToListNum(int listNum, Type data) {
    if(listNum <= this->list.getSize()){
        this->list.getAt(listNum).push_back(data);
    } else {
        cout << "Pushing to unidentified list" << endl;
        throw 420;
    }
}

template<typename Type>
void DSAdjList<Type>::addToListName(const Type & listName, Type data) {
    int found = find(listName);
    if(found >= 0){
        this->addToListNum(found, data);
    }
}

template<typename Type>
void DSAdjList<Type>::add(Type data) {
    DSList<Type> newList;
    newList.push_back(data);
    this->list.push_back(newList);
}

template<typename Type>
int DSAdjList<Type>::listSize(int index) {
    return this->list.getAt(index).getSize();
}

template<typename Type>
int DSAdjList<Type>::totalSize() {
    return this->list.getSize();
}

template<typename Type>
Type DSAdjList<Type>::atNum(int listNum, int index) {
    return this->list.getAt(listNum).getAt(index);
}

template<typename Type>
Type DSAdjList<Type>::atName(Type listName, int index) {
    int found = find(listName);
    return this->list.getAt(found).getAt(index);
}



#endif //INC_20F_FLT_PLN_DSADJLIST_H
