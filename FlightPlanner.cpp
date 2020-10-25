//
// Created by Kevin Leong on 10/24/20.
//

#include "FlightPlanner.h"

void clearCArray(char* charArray){
    for(int i = 0; i < 100; ++i){
        charArray[i] = (char)0;
    }
}

void setString(DSString& out, char* charArray, ifstream &inFile, char dlm){
    inFile.getline(charArray, 100, dlm);
    out = charArray;
    clearCArray(charArray);
}
void setInt(int& out, char* charArray, ifstream &inFile, char dlm){
    inFile.getline(charArray, 100, dlm);
    out = atoi(charArray);
    clearCArray(charArray);
}

void getFlights(ifstream &inFlightFile, FlightAdjList &flightAdjList){
    char numFlightsC[10];
    inFlightFile.getline(numFlightsC, 10, '\n');
    int numFlights = atoi(numFlightsC);

    for(int i = 0; i < numFlights; ++i){
        char inputArray[100];

        DSString flightOrigin;
        setString(flightOrigin, inputArray, inFlightFile, '|');

        DSString flightDest;
        setString(flightDest, inputArray, inFlightFile, '|');

        int cost;
        setInt(cost, inputArray, inFlightFile, '|');
        int time;
        setInt(time, inputArray, inFlightFile, '|');

        DSString airline;
        setString(airline, inputArray, inFlightFile, '\n');

        Flight flight(flightOrigin, flightDest, cost, time, airline);
        Flight oppositeFlight(flightDest, flightOrigin, cost, time, airline);

        int found = flightAdjList.find(flight.getOrigin());
        if(found >= 0){
            flightAdjList.addToListNum(found, flight);
        } else {
            flightAdjList.add(flight);
        }

        found = flightAdjList.find(oppositeFlight.getOrigin());
        if(found >= 0){
            flightAdjList.addToListNum(found, oppositeFlight);
        } else {
            flightAdjList.add(oppositeFlight);
        }

    }
}

void backtrackFlights(FlightAdjList &flightAdjList,
        const DSString& wantedOrigin, const DSString& wantedDestination){

    int wantedListNum = flightAdjList.find(wantedOrigin);
    DSStack<Flight> flightStack;

    DSList<Flight> savedPaths;

    //Trying to figure outt how to backtrack RECURSIVELY
    //Pointers?
    //FROM LEC
    Flight* curr = &flightAdjList.at(wantedListNum).getAt(0);

    flightStack.push(flightAdjList.at(wantedListNum).getAt(0));
    while(flightStack.getSize() != 0){
        if(flightStack.top().getDestination() == wantedDestination){
            savedPaths = flightStack.saveStack();
            flightStack.pop();
        } else{

        }
    }

    //MY CODE
    for(int i = 0; i < flightAdjList.at(wantedListNum).getSize(); ++i){
        Flight checkFlight = flightAdjList.at(wantedListNum).getAt(i);
        flightStack.push(checkFlight);
        if(checkFlight.getDestination() == wantedDestination){
            savedPaths = flightStack.saveStack();
        }else{
            int find = flightAdjList.find(checkFlight.getOrigin());
        }
    }

}

void findFlights(FlightAdjList &flightAdjList, ifstream &inFile){
    char* inputChar = new char[100];
    DSString wantedOrigin;
    setString(wantedOrigin, inputChar, inFile, '|');
    DSString wantedDestination;
    setString(wantedDestination, inputChar, inFile, '|');

    DSAdjList<DSString> savedPaths;
    backtrackFlights(flightAdjList, wantedOrigin, wantedDestination);

}

void runFlightPlanner(ifstream &inFlightFile, ifstream &inFile) {
    FlightAdjList flightAdjList;
    getFlights(inFlightFile, flightAdjList);
    //flightAdjList.printAdjList();

    char requestC[10];
    inFile.getline(requestC, 10, '\n');
    int numRequest = atoi(requestC);

    for(int i = 0; i < numRequest; ++i){
        findFlights(flightAdjList, inFile);
    }
}
