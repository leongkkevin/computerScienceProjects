//
// Created by Kevin Leong on 10/24/20.
//

#ifndef INC_20F_FLT_PLN_FLIGHT_H
#define INC_20F_FLT_PLN_FLIGHT_H


#include "DSString.h"

class Flight {
private:
    DSString origin;
    DSString destination;

    int cost;
    int time;

    DSString airline;

public:
    Flight();
    Flight(const DSString& origin, const DSString& destination,
            int cost, int time, const DSString& airline);
    Flight(const Flight& copy);

    DSString getOrigin();
};


#endif //INC_20F_FLT_PLN_FLIGHT_H
