//
// Created by Kevin Leong on 10/24/20.
//

#include "FlightAdjList.h"

FlightAdjList::FlightAdjList() = default;

//searches the origins of each flight
//will return -1 if no flights of that origin is found
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

void FlightAdjList::addToListNum(int listNum, const Flight& data) {
    //Flight newFlight(data);
    if(listNum <= this->flightList.getSize()){
        this->flightList.getAt(listNum).push_back(data);
    } else {
        cout << "Pushing to unidentified list" << endl;
        throw 420;
    }
}

void FlightAdjList::add(const Flight& data) {
    DSList<Flight> newList;
    newList.push_back(data);
    this->flightList.push_back(newList);
}
void FlightAdjList::addList(const DSList<Flight>& newList) {
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
        int amountLayovers = flightList.getAt(f).getSize();
        if(amountLayovers >= 1){
            sumCost += amountLayovers * 19;
        }
        totalCosts[f] = sumCost;
    }

    float min;
    int minIndex;

    int printAmt = 0;
    if(this->flightList.getSize() < 3){
        printAmt = flightList.getSize();
    } else{
        printAmt = 3;
    }
    for(int count = 0; count < printAmt; count++){
        min = totalCosts[0];
        minIndex = 0;
        for (int i = 0; i < size; ++i) {
            if (min > totalCosts[i]) {
                min = totalCosts[i];
                minIndex = i;
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
    int *totalTime = new int[size];

    for(int f = 0; f < size; ++f){
        int sumTime = 0;
        int listSize = this->flightList.getAt(f).getSize();
        for(int g = 0; g < listSize; ++g){
            sumTime += this->flightList.getAt(f).getAt(g).getTime();
        }
        int amountLayovers = flightList.getAt(f).getSize() - 1;
        if(amountLayovers >= 1){
            sumTime += amountLayovers * 43;
        }
        totalTime[f] = sumTime;
    }

    int min;
    int minIndex;

    int printAmt = 0;
    if(this->flightList.getSize() < 3){
        printAmt = flightList.getSize();
    } else{
        printAmt = 3;
    }
    for(int count = 0; count < printAmt; count++){
        min = totalTime[0];
        minIndex = 0;
        for (int j = 0; j < size; ++j) {
            int ch = totalTime[j];
            if (min > totalTime[j]) {
                min = totalTime[j];
                minIndex = j;
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
