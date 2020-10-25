//
// Created by Kevin Leong on 10/24/20.
//

#include "FlightAdjList.h"

FlightAdjList::FlightAdjList() {
}

int FlightAdjList::find(const DSString &search) {
    if(this->flightList.getSize() == 0){
        return -1;
    }

    for(int i = 0; i < this->flightList.getSize(); ++i){
        DSString originString = this->flightList.getAt(i).getAt(0).getOrigin();
        if(originString == search){
            return i;
        }
    }
    return -1;
}

void FlightAdjList::addToListNum(int listNum, Flight data) {
    if(listNum <= this->flightList.getSize()){
        this->flightList.getAt(listNum).push_back(data);
    } else {
        cout << "Pushing to unidentified list" << endl;
        throw 420;
    }
}

void FlightAdjList::add(Flight data) {
    DSList<Flight> newList;
    newList.push_back(data);
    this->flightList.push_back(newList);
}

DSList<Flight> FlightAdjList::at(int index) {
    return this->flightList.getAt(index);
}


int FlightAdjList::getSize() {
    return this->flightList.getSize();
}

void FlightAdjList::printAdjList(){
    for(int i = 0; i < flightList.getSize(); ++i){
        for(int j = 0; j < flightList.getAt(i).getSize(); ++j){
            flightList.getAt(i).getAt(j).printFlight();
        }
    }
}