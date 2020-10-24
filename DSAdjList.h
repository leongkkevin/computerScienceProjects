//
// Created by Kevin Leong on 10/21/20.
//

#include "DSList.h"
#include "Flight.h"

#ifndef INC_20F_FLT_PLN_DSADJLIST_H
#define INC_20F_FLT_PLN_DSADJLIST_H

class DSAdjList {
private:
    //DSList<DSList<Flight>> flightList;

public:
//    DSAdjList();
//
//    int find(DSString search);
//
//    void addToListNum(int listNum, Flight data);
//    void addToListName(const DSString &listName, DSString data);
//    void add(Flight data);
//
//    int listSize(int position);
//    int totalSize();
//
//    Flight atNum(int listNum, int index);
//    Flight atName(DSString listName, int index);

};

//DSAdjList::DSAdjList() {
//}
//
//int DSAdjList::find(DSString search) {
//    for(int i = 0; i < this->flightList.getSize(); ++i){
//        if(this->flightList.getAt(i).getAt(0).getOrigin() == search){
//            return i;
//        }
//    }
//    return -1;
//}
//
//void DSAdjList::addToListNum(int listNum, Flight data) {
//    if(listNum <= this->flightList.getSize()){
//        this->flightList.getAt(listNum).push_back(data);
//    } else {
//        cout << "Pushing to unidentified list" << endl;
//        throw 420;
//    }
//}

//
//template<typename Type>
//void DSAdjList<Type>::addToListName(const Type & listName, Type data) {
//    int found = find(listName);
//    if(found >= 0){
//        this->addToListNum(found, data);
//    }
//}
//

//void DSAdjList::add(Flight data) {
//    int found = find(data.getOrigin());
//    if(found >= 0){
//        DSList<Flight> newList;
//        this->flightList.push_back(newList);
//    } else {
//        addToListNum(found, data);
//    }
//}
//
//template<typename Type>
//int DSAdjList<Type>::listSize(int index) {
//    return this->list.getAt(index).getSize();
//}
//
//template<typename Type>
//int DSAdjList<Type>::totalSize() {
//    return this->list.getSize();
//}
//
//template<typename Type>
//Type DSAdjList<Type>::atNum(int listNum, int index) {
//    return this->list.getAt(listNum).getAt(index);
//}
//
//template<typename Type>
//Type DSAdjList<Type>::atName(Type listName, int index) {
//    int found = find(listName);
//    return this->list.getAt(found).getAt(index);
//}


#endif //INC_20F_FLT_PLN_DSADJLIST_H
