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
        const DSString& wantedOrigin, const DSString& wantedDestination,
        FlightAdjList &savedFlights){

    int wantedListNum = flightAdjList.find(wantedOrigin);
    DSStack<Flight> flightStack;

    DSList<Flight> savedPaths;

    for(int j = 0; j < flightAdjList.at(wantedListNum).getSize(); ++j ) {

        flightStack.push(flightAdjList.at(wantedListNum).getAt(j));

        DSStack<int> iStack;
        int i = 0;
        while (!flightStack.isEmpty()) {
            if (flightStack.top().getDestination() == wantedDestination) {
                savedPaths = flightStack.saveStack();
                savedFlights.addList(savedPaths);
                flightStack.pop();
                if(!iStack.isEmpty()){
                    i = iStack.pop();
                }
                i++;
            } else {
                DSString destination = flightStack.top().getDestination();
                int dest = flightAdjList.find(flightStack.top().getDestination());
                int size = flightAdjList.at(dest).getSize();

                for (i; i < size; ++i) {
                    Flight checkFlight = flightAdjList.at(dest).getAt(i);
                    if (flightStack.searchStack(checkFlight)) {
                        continue;
                    } else {
                        Flight pushFlight = flightAdjList.at(dest).getAt(i);
                        flightStack.push(pushFlight);
                        iStack.push(i);
                        i = 0;
                        break;
                    }
                }
                if (i == size && !iStack.isEmpty()) {
                    flightStack.pop();
                    i = iStack.pop();
                    i++;
                } else if(iStack.isEmpty()){
                    flightStack.pop();
                    break;
                }
            }
        }
    }
}

void findFlights(FlightAdjList &flightAdjList, ifstream &inFile, FlightAdjList &savedFlights){
    char* inputChar = new char[100];
    DSString wantedOrigin;
    setString(wantedOrigin, inputChar, inFile, '|');
    DSString wantedDestination;
    setString(wantedDestination, inputChar, inFile, '|');

    backtrackFlights(flightAdjList, wantedOrigin, wantedDestination, savedFlights);

    if(savedFlights.getSize() == 0){
        Flight noFlight(wantedOrigin, wantedDestination, 0, 0, "None");
        savedFlights.add(noFlight);
    }

    delete[] inputChar;
}

void sortFlights(FlightAdjList &savedFlights, const DSString &sortBy, FlightAdjList &organizedFlights){
    if(sortBy == "C"){
        //cout << "BY COST: " << endl;
        organizedFlights = savedFlights.sortByCost();
    } else if(sortBy == "T"){
        //cout << "BY TIME: " << endl;
        organizedFlights = savedFlights.sortByTime();
    }

    //organizedFlights.printAdjList();
}

void printFlights(FlightAdjList &organizedFlights, ofstream &outFile){

}

void runFlightPlanner(ifstream &inFlightFile, ifstream &inFile, ofstream &outFile) {
    FlightAdjList flightAdjList;
    getFlights(inFlightFile, flightAdjList);
    //flightAdjList.printAdjList();

    char requestC[10];
    inFile.getline(requestC, 10, '\n');
    int numRequest = atoi(requestC);

    for(int i = 0; i < numRequest; ++i){
        FlightAdjList savedFlights;
        findFlights(flightAdjList, inFile, savedFlights);

        char sortByC[3];
        inFile.getline(sortByC, 5, '\n');
        DSString sortBy = sortByC;
        //savedFlights.printAdjList();

        FlightAdjList organizedFlights;
        sortFlights(savedFlights, sortBy, organizedFlights);
        //organizedFlights.printAdjList();

        printFlights(organizedFlights, outFile);
    }
}
