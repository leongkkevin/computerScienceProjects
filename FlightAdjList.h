
//
// Created by Kevin Leong on 10/24/20.
//

#include "DSList.h"
#include "Flight.h"

#ifndef INC_20F_FLT_PLN_FLIGHTADJLIST_H
#define INC_20F_FLT_PLN_FLIGHTADJLIST_H


class FlightAdjList {
private:
    DSList<DSList<Flight>> flightList;

public:
    FlightAdjList();
    int find(const DSString &search);

    void addToListNum(int listNum, Flight data);
    void add(Flight data);
    void addList(DSList<Flight> newList);

    DSList<Flight> at(int index);

    int getSize();

    void printAdjList();

};


#endif //INC_20F_FLT_PLN_FLIGHTADJLIST_H
