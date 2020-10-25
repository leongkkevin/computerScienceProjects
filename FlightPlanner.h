//
// Created by Kevin Leong on 10/24/20.
//

#include <iostream>
#include <fstream>

#include "Flight.h"
#include "FlightAdjList.h"

#include "DSAdjList.h"
#include "DSStack.h"

using namespace std;

#ifndef INC_20F_FLT_PLN_FLIGHTPLANNER_H
#define INC_20F_FLT_PLN_FLIGHTPLANNER_H


void getFlights(ifstream &inFile);
void runFlightPlanner(ifstream &inFlightFile, ifstream &inFile);



#endif //INC_20F_FLT_PLN_FLIGHTPLANNER_H
