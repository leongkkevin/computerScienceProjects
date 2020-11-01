
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
    ~FlightAdjList() = default;
    int find(const DSString &search);

    void addToListNum(int listNum, const Flight& data);
    void add(const Flight& data);
    void addList(const DSList<Flight>& newList);

    DSList<Flight> at(int index);

    FlightAdjList sortByCost();
    FlightAdjList sortByTime();

    int getSize();

    void printAdjList();

};


#endif //INC_20F_FLT_PLN_FLIGHTADJLIST_H
