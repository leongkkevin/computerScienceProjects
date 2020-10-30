//
// Created by Kevin Leong on 10/24/20.
//

#include <iostream>

using namespace std;

#ifndef INC_20F_FLT_PLN_FLIGHT_H
#define INC_20F_FLT_PLN_FLIGHT_H


#include "DSString.h"

class Flight {
private:
    DSString origin;
    DSString destination;

    float cost;
    int time;

    DSString airline;

public:
    Flight();
    Flight(const DSString& origin, const DSString& destination,
           float cost, int time, const DSString& airline);
    Flight(const Flight& copy);

    DSString getOrigin();
    DSString getDestination();
    float getCost();
    int getTime();
    DSString getAirline();

    void printFlight();

    bool operator== (const Flight&) const;
};


#endif //INC_20F_FLT_PLN_FLIGHT_H
