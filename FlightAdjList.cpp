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
void FlightAdjList::addList(DSList<Flight> newList) {
    this->flightList.push_back(newList);
}

DSList<Flight> FlightAdjList::at(int index) {
    return this->flightList.getAt(index);
}


int FlightAdjList::getSize() {
    return this->flightList.getSize();
}

FlightAdjList FlightAdjList::sortByCost(){
    FlightAdjList sortedFlights;

    int size = this->flightList.getSize();
    float *totalCosts = new float[size];

    for(int f = 0; f < size; ++f){
        float sumCost = 0;
        int listSize = this->flightList.getAt(f).getSize();
        for(int g = 0; g < listSize; ++g){
            sumCost += this->flightList.getAt(f).getAt(g).getCost();
        }
        totalCosts[f] = sumCost;
    }

    float min;
    int minIndex;
    for(int count = 0; count < 3; count++){
        for (int i = 0; i < size; ++i) {
            min = totalCosts[i];
            for (int j = 0; j < size; ++j) {
                if (min > totalCosts[j]) {
                    min = totalCosts[j];
                    minIndex = j;
                }
            }
        }
        sortedFlights.addList(flightList.getAt(minIndex));
        totalCosts[minIndex] = 999999999;
    }

    delete[] totalCosts;
    return sortedFlights;
}
FlightAdjList FlightAdjList::sortByTime(){
    FlightAdjList sortedFlights;

    int size = this->flightList.getSize();
    float *totalTime = new float[size];

    for(int f = 0; f < size; ++f){
        float sumTime = 0;
        int listSize = this->flightList.getAt(f).getSize();
        for(int g = 0; g < listSize; ++g){
            sumTime += this->flightList.getAt(f).getAt(g).getCost();
        }
        totalTime[f] = sumTime;
    }

    float min;
    int minIndex;
    for(int count = 0; count < 3; count++){
        for (int i = 0; i < size; ++i) {
            min = totalTime[i];
            minIndex = i;
            for (int j = 0; j < size; ++j) {
                if (min > totalTime[j]) {
                    min = totalTime[j];
                    minIndex = j;
                }
            }
        }
        sortedFlights.addList(flightList.getAt(minIndex));
        totalTime[minIndex] = 999999999;
    }

    delete[] totalTime;
    return sortedFlights;
}

void FlightAdjList::printAdjList(){
    if(flightList.getSize() == 0){
        cout << "No flights" << endl;
    }
    for(int i = 0; i < flightList.getSize(); ++i){
        for(int j = 0; j < flightList.getAt(i).getSize(); ++j){
            flightList.getAt(i).getAt(j).printFlight();
        }
        cout << "============================" << endl;
    }
    cout << "============================" << endl;
}
