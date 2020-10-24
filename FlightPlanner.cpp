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

void getFlights(ifstream &inFile, FlightAdjList &flightAdjList){
    char numFlightsC[10];
    inFile.getline(numFlightsC, 10, '\n');
    int numFlights = atoi(numFlightsC);

    for(int i = 0; i < numFlights; ++i){
        char inputArray[100];

        DSString flightOrigin;
        setString(flightOrigin, inputArray, inFile, '|');

        DSString flightDest;
        setString(flightDest, inputArray, inFile, '|');

        int cost;
        setInt(cost, inputArray, inFile, '|');
        int time;
        setInt(time, inputArray, inFile, '|');

        DSString airline;
        setString(airline, inputArray, inFile, '\n');

        Flight flight(flightOrigin, flightDest, cost, time, airline);

        int found = flightAdjList.find(flightOrigin);
        if(found >= 0){
            flightAdjList.addToListNum(found, flight);
        } else {
            flightAdjList.add(flight);
        }

    }
}

void runFlightPlanner(ifstream &inFile, ofstream &outFile) {
    FlightAdjList flightAdjList;
    getFlights(inFile, flightAdjList);

}
