//
// Created by Kevin Leong on 10/24/20.
//

#include "Flight.h"

Flight::Flight() {
    this->origin = "";
    this->destination = "";
    this->airline = "";

    this->cost = 0;
    this->time = 0;
}

Flight::Flight(const DSString& origin, const DSString& destination,
        int cost, int time,
        const DSString& airline) {

    this->origin = origin;
    this->destination = destination;
    this->cost = cost;
    this->time = time;
    this->airline = airline;
}

Flight::Flight(const Flight& copy) {
    this->origin = copy.origin;
    this->destination = copy.destination;
    this->cost = copy.cost;
    this->time = copy.time;
    this->airline = copy.airline;
}

DSString Flight::getOrigin() {
    return this->origin;
}
