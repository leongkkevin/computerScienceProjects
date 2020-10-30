//
// Created by Kevin Leong on 10/21/20.
//

#include "catch.hpp"

#include "DSString.h"
#include "Flight.h"

#include "DSList.h"
#include "DSStack.h"
#include "FlightAdjList.h"


TEST_CASE("Linked List Class", "[LinkedList]"){
    DSList<int> intList;
    intList.push_back(1);
    intList.push_back(10);
    intList.push_back(100);

    DSList<char> charList;
    charList.push_back('a');
    charList.push_back('\n');
    charList.push_back(' ');

    DSList<DSString> stringList;
    stringList.push_back("test String");
    stringList.push_back("test");
    stringList.push_back(" ");

    SECTION("Copy Constructor"){
        DSList<int> intCopyList = DSList<int> (intList);
        REQUIRE(intCopyList.getSize() == intList.getSize());
        REQUIRE(intCopyList.getAt(0) == intList.getAt(0));

        DSList<char> charCopyList = DSList<char> (charList);
        REQUIRE(charCopyList.getSize() == charList.getSize());
        REQUIRE(charCopyList.getAt(1) == charList.getAt(1));

        DSList<DSString> stringCopyList = DSList<DSString> (stringList);
        REQUIRE(stringCopyList.getSize() == stringList.getSize());
        REQUIRE(stringCopyList.getAt(2) == stringList.getAt(2));
    }

    SECTION("Push_back"){
        intList.push_back(2);
        REQUIRE(intList.getAt(0) == 1);
        REQUIRE(intList.getAt(3) == 2);
        REQUIRE(intList.getSize() == 4);

        charList.push_back('b');
        REQUIRE(charList.getAt(0) == 'a');
        REQUIRE(charList.getAt(3) == 'b');
        REQUIRE(charList.getSize() == 4);

        stringList.push_back("a test sentence");
        REQUIRE(stringList.getAt(0) == "test String");
        REQUIRE(stringList.getAt(3) == "a test sentence");
        REQUIRE(stringList.getSize() == 4);
    }

    SECTION("Remove"){
        intList.remove(1);
        REQUIRE(intList.getSize() == 2);
        REQUIRE(intList.getAt(0) == 10);

        charList.remove('a');
        REQUIRE(charList.getSize() == 2);
        REQUIRE(charList.getAt(0) == '\n');

        stringList.remove("test String");
        REQUIRE(stringList.getSize() == 2);
        REQUIRE(stringList.getAt(0) == "test");
    }

    SECTION("Remove At"){
        intList.removeAt(1);
        REQUIRE(intList.getSize() == 2);
        REQUIRE(intList.getAt(1) == 100);

        charList.removeAt(0);
        REQUIRE(charList.getSize() == 2);
        REQUIRE(charList.getAt(0) == '\n');

        stringList.removeAt(3);
        REQUIRE(stringList.getSize() == 2);
        REQUIRE(stringList.getAt(stringList.getSize() - 1) == "test");
    }

    SECTION("Pop"){
        REQUIRE(intList.pop() == 100);
        REQUIRE(intList.getSize() == 2);
        REQUIRE(intList.getAt(0) == 1);

        REQUIRE(charList.pop() == ' ');
        REQUIRE(charList.getSize() == 2);
        REQUIRE(charList.getAt(0) == 'a');

        REQUIRE(stringList.pop() == " ");
        REQUIRE(stringList.getSize() == 2);
        REQUIRE(stringList.getAt(0) == "test String");
    }

    SECTION("Search"){
        REQUIRE(intList.search(1) == 0);
        REQUIRE(intList.search(10) == 1);
        REQUIRE(intList.search(100) == 2);

        REQUIRE(charList.search('a') == 0);
        REQUIRE(charList.search('\n') == 1);
        REQUIRE(charList.search(' ') == 2);

        REQUIRE(stringList.search("test String") == 0);
        REQUIRE(stringList.search("test") == 1);
        REQUIRE(stringList.search(" ") == 2);
    }

    SECTION("Equals Operator"){
        DSList<int> newIntList = intList;
        REQUIRE(newIntList.getSize() == intList.getSize());
        REQUIRE(newIntList.getAt(0) == intList.getAt(0));
        REQUIRE(newIntList.getAt(1) == intList.getAt(1));
        REQUIRE(newIntList.getAt(2) == intList.getAt(2));

        DSList<char> newCharList = charList;
        REQUIRE(newCharList.getSize() == charList.getSize());
        REQUIRE(newCharList.getAt(0) == charList.getAt(0));
        REQUIRE(newCharList.getAt(1) == charList.getAt(1));
        REQUIRE(newCharList.getAt(2) == charList.getAt(2));

        DSList<DSString> newStringList = stringList;
        REQUIRE(newStringList.getSize() == stringList.getSize());
        REQUIRE(newStringList.getAt(0) == stringList.getAt(0));
        REQUIRE(newStringList.getAt(1) == stringList.getAt(1));
        REQUIRE(newStringList.getAt(2) == stringList.getAt(2));
    }

}

TEST_CASE("DSStack Class", "[Stack]"){
    DSStack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    DSStack<char> charStack;
    charStack.push('a');
    charStack.push(' ');
    charStack.push('#');

    DSStack<DSString> stringStack;
    stringStack.push("plane");
    stringStack.push(" ");
    stringStack.push("!!!");

    SECTION("Push Test"){
        intStack.push(4);
        REQUIRE(intStack.getSize() == 4);
        intStack.push(5);
        REQUIRE(intStack.getSize() == 5);
        REQUIRE(intStack.pop() == 5);
        REQUIRE(intStack.pop() == 4);

        charStack.push('?');
        REQUIRE(charStack.getSize() == 4);
        charStack.push(' ');
        REQUIRE(charStack.getSize() == 5);
        REQUIRE(charStack.pop() == ' ');
        REQUIRE(charStack.pop() == '?');

        stringStack.push("hello");
        REQUIRE(stringStack.getSize() == 4);
        stringStack.push("cheese");
        REQUIRE(stringStack.getSize() == 5);
        REQUIRE(stringStack.pop() == "cheese");
        REQUIRE(stringStack.pop() == "hello");
    }

    SECTION("Pop Test"){
        REQUIRE(intStack.pop() == 3);
        REQUIRE(intStack.getSize() == 2);
        REQUIRE(intStack.pop() == 2);
        REQUIRE(intStack.getSize() == 1);
        REQUIRE(intStack.pop() == 1);
        REQUIRE(intStack.getSize() == 0);
        REQUIRE(intStack.isEmpty());

        REQUIRE(charStack.pop() == '#');
        REQUIRE(charStack.getSize() == 2);
        REQUIRE(charStack.pop() == ' ');
        REQUIRE(charStack.getSize() == 1);
        REQUIRE(charStack.pop() == 'a');
        REQUIRE(charStack.getSize() == 0);
        REQUIRE(charStack.isEmpty());

        REQUIRE(stringStack.pop() == "!!!");
        REQUIRE(stringStack.getSize() == 2);
        REQUIRE(stringStack.pop() == " ");
        REQUIRE(stringStack.getSize() == 1);
        REQUIRE(stringStack.pop() == "plane");
        REQUIRE(stringStack.getSize() == 0);
        REQUIRE(stringStack.isEmpty());
    }

    SECTION("Copy Constructor"){
        DSStack<int> intStack2(intStack);
        REQUIRE(intStack2.getSize() == intStack.getSize());
        REQUIRE(intStack2.pop() == intStack.pop());
        REQUIRE(intStack2.pop() == intStack.pop());
        REQUIRE(intStack2.pop() == intStack.pop());

        DSStack<char> charStack2(charStack);
        REQUIRE(charStack2.getSize() == charStack.getSize());
        REQUIRE(charStack2.pop() == charStack.pop());
        REQUIRE(charStack2.pop() == charStack.pop());
        REQUIRE(charStack2.pop() == charStack.pop());

        DSStack<DSString> stringStack2(stringStack);
        REQUIRE(stringStack2.getSize() == stringStack.getSize());
        REQUIRE(stringStack2.pop() == stringStack.pop());
        REQUIRE(stringStack2.pop() == stringStack.pop());
        REQUIRE(stringStack2.pop() == stringStack.pop());
    }

    SECTION("= Operator"){
        DSStack<int> intStack2;
        intStack2 = intStack;
        REQUIRE(intStack2.getSize() == intStack.getSize());
        REQUIRE(intStack2.pop() == intStack.pop());
        REQUIRE(intStack2.pop() == intStack.pop());
        REQUIRE(intStack2.pop() == intStack.pop());

        DSStack<char> charStack2;
        charStack2 = charStack;
        REQUIRE(charStack2.getSize() == charStack.getSize());
        REQUIRE(charStack2.pop() == charStack.pop());
        REQUIRE(charStack2.pop() == charStack.pop());
        REQUIRE(charStack2.pop() == charStack.pop());

        DSStack<DSString> stringStack2;
        stringStack2 = stringStack;
        REQUIRE(stringStack2.getSize() == stringStack.getSize());
        REQUIRE(stringStack2.pop() == stringStack.pop());
        REQUIRE(stringStack2.pop() == stringStack.pop());
        REQUIRE(stringStack2.pop() == stringStack.pop());
    }

    SECTION("Peek Test"){
        REQUIRE(intStack.peek() == 3);
        REQUIRE(intStack.getSize() == 3);
        intStack.pop();
        REQUIRE(intStack.peek() == 2);
        REQUIRE(intStack.getSize() == 2);
        intStack.pop();
        REQUIRE(intStack.peek() == 1);
        REQUIRE(intStack.getSize() == 1);
        intStack.pop();
        REQUIRE(intStack.isEmpty());

        REQUIRE(charStack.peek() == '#');
        REQUIRE(charStack.getSize() == 3);
        charStack.pop();
        REQUIRE(charStack.peek() == ' ');
        REQUIRE(charStack.getSize() == 2);
        charStack.pop();
        REQUIRE(charStack.peek() == 'a');
        REQUIRE(charStack.getSize() == 1);
        charStack.pop();
        REQUIRE(charStack.isEmpty());

        REQUIRE(stringStack.peek() == "!!!");
        REQUIRE(stringStack.getSize() == 3);
        stringStack.pop();
        REQUIRE(stringStack.peek() == " ");
        REQUIRE(stringStack.getSize() == 2);
        stringStack.pop();
        REQUIRE(stringStack.peek() == "plane");
        REQUIRE(stringStack.getSize() == 1);
        stringStack.pop();
        REQUIRE(stringStack.isEmpty());
    }

    SECTION("Save Stack Test"){
        DSList<int> intList;
        intList = intStack.saveStack();
        REQUIRE(intList.getSize() == intStack.getSize());
        REQUIRE(intList.getAt(0) == 1);
        REQUIRE(intList.getAt(1) == 2);
        REQUIRE(intList.getAt(2) == 3);

        DSList<char> charList;
        charList = charStack.saveStack();
        REQUIRE(charList.getSize() == charStack.getSize());
        REQUIRE(charList.getAt(0) == 'a');
        REQUIRE(charList.getAt(1) == ' ');
        REQUIRE(charList.getAt(2) == '#');

        DSList<DSString> stringList;
        stringList = stringStack.saveStack();
        REQUIRE(stringList.getSize() == stringStack.getSize());
        REQUIRE(stringList.getAt(0) == "plane");
        REQUIRE(stringList.getAt(1) == " ");
        REQUIRE(stringList.getAt(2) == "!!!");
    }

    SECTION("Top Test"){
        REQUIRE(intStack.top() == 3);
        intStack.push(10);
        REQUIRE(intStack.top() == 10);
        intStack.pop();
        intStack.pop();
        REQUIRE(intStack.top() == 2);

        REQUIRE(charStack.top() == '#');
        charStack.push('K');
        REQUIRE(charStack.top() == 'K');
        charStack.pop();
        charStack.pop();
        REQUIRE(charStack.top() == ' ');

        REQUIRE(stringStack.top() == "!!!");
        stringStack.push("Kevin");
        REQUIRE(stringStack.top() == "Kevin");
        stringStack.pop();
        stringStack.pop();
        REQUIRE(stringStack.top() == " ");
    }

    SECTION("Search Stack Test"){
        REQUIRE(intStack.searchStack(1) == true);
        REQUIRE(intStack.searchStack(2) == true);
        REQUIRE(intStack.searchStack(4) == false);
        intStack.push(4);
        REQUIRE(intStack.searchStack(4) == true);

        REQUIRE(charStack.searchStack('a') == true);
        REQUIRE(charStack.searchStack(' ') == true);
        REQUIRE(charStack.searchStack('&') == false);
        charStack.push('&');
        REQUIRE(charStack.searchStack('&') == true);

        REQUIRE(stringStack.searchStack("plane") == true);
        REQUIRE(stringStack.searchStack(" ") == true);
        REQUIRE(stringStack.searchStack("Jeff") == false);
        stringStack.push("Jeff");
        REQUIRE(stringStack.searchStack("Jeff") == true);
    }

}

TEST_CASE("Adjacency List Class", "[AdjList]"){
    FlightAdjList flightAdjList;

    for(int i = 0; i < 3; ++i){
        DSList<Flight> flightList;

        char iChar = '0' + i + 1;
        DSString iString(iChar);

        for(int j = 0; j < 3; ++j){
            char jChar = '0' + j + 1;
            DSString jString(jChar);

            DSString prefix = iString + "/" + jString;

            DSString origin = prefix + " Origin";
            DSString destination = prefix + " Destination";
            DSString airline = prefix + " Airline";
            Flight flight(origin, destination, j + 1 *10, j + 1 * 100, airline);
            flightList.push_back(flight);
        }
        flightAdjList.addList(flightList);
    }

    SECTION("Find Test"){
        REQUIRE(flightAdjList.find("1/1 Origin") == 0);
        REQUIRE(flightAdjList.find("2/1 Origin") == 1);
        REQUIRE(flightAdjList.find("3/1 Origin") == 2);
        REQUIRE(flightAdjList.find("Any Origin") == -1);
    }

    SECTION("Add To List Num Test"){
        Flight addFlight("NewO", "NewD", 100, 200, "Plane");
        flightAdjList.addToListNum(0, addFlight);
        REQUIRE(flightAdjList.at(0).getSize() == 4);
        REQUIRE(flightAdjList.at(0).getAt(3).getOrigin() == "NewO");
        REQUIRE(flightAdjList.at(0).getAt(3).getDestination() == "NewD");

        flightAdjList.addToListNum(1, addFlight);
        REQUIRE(flightAdjList.at(1).getSize() == 4);
        REQUIRE(flightAdjList.at(1).getAt(3).getCost() == 100);
        REQUIRE(flightAdjList.at(1).getAt(3).getTime() == 200);

        flightAdjList.addToListNum(2, addFlight);
        REQUIRE(flightAdjList.at(2).getSize() == 4);
        REQUIRE(flightAdjList.at(2).getAt(3).getOrigin() == "NewO");
        REQUIRE(flightAdjList.at(2).getAt(3).getTime() == 200);
    }

    SECTION("Add Test"){
        Flight addFlight("Here", "There", 500, 1000, "Zoom");
        flightAdjList.add(addFlight);
        REQUIRE(flightAdjList.getSize() == 4);
        REQUIRE(flightAdjList.at(3).getAt(0).getOrigin() == "Here");
        REQUIRE(flightAdjList.at(3).getAt(0).getDestination() == "There");
        REQUIRE(flightAdjList.at(3).getAt(0).getCost() == 500);
        REQUIRE(flightAdjList.at(3).getAt(0).getTime() == 1000);
    }

    SECTION("Add List Test"){
        Flight aFlight1("1Start", "1End", 50, 500, "Fly");
        Flight aFlight2("2Start", "2End", 60, 600, "Drift");
        Flight aFlight3("3Start", "3End", 70, 700, "Sail");
        DSList<Flight> newList;
        newList.push_back(aFlight1); newList.push_back(aFlight2); newList.push_back(aFlight3);
        flightAdjList.addList(newList);

        REQUIRE(flightAdjList.getSize() == 4);
        REQUIRE(flightAdjList.at(3).getAt(0).getOrigin() == "1Start");
        REQUIRE(flightAdjList.at(3).getAt(1).getDestination() == "2End");
        REQUIRE(flightAdjList.at(3).getAt(2).getCost() == 70);
    }

    SECTION("Sort By Cost Test"){
        Flight f1("1", "1", 100, 300, "Air");
        Flight f2("2", "2", 60, 200, "Air");
        Flight f3("3", "3", 10, 100, "Air");
        DSList<Flight> l1;
        l1.push_back(f1); l1.push_back(f3); l1.push_back(f1);
        DSList<Flight> l2;
        l2.push_back(f2); l2.push_back(f2); l2.push_back(f2);
        DSList<Flight> l3;
        l3.push_back(f3); l3.push_back(f2); l3.push_back(f1);
        FlightAdjList newAdjList;
        newAdjList.addList(l1); newAdjList.addList(l2); newAdjList.addList(l3);
        FlightAdjList sortedAdjList = newAdjList.sortByCost();

        REQUIRE(sortedAdjList.getSize() == flightAdjList.getSize());
//      321;   222; 131
        REQUIRE(sortedAdjList.at(0).getAt(0).getOrigin() == "3");
        REQUIRE(sortedAdjList.at(0).getAt(1).getDestination() == "2");
        REQUIRE(sortedAdjList.at(0).getAt(2).getCost() == 100);
        REQUIRE(sortedAdjList.at(1).getAt(0).getOrigin() == "2");
        REQUIRE(sortedAdjList.at(1).getAt(1).getDestination() == "2");
        REQUIRE(sortedAdjList.at(1).getAt(2).getCost() == 60);
        REQUIRE(sortedAdjList.at(2).getAt(0).getOrigin() == "1");
        REQUIRE(sortedAdjList.at(2).getAt(1).getDestination() == "3");
        REQUIRE(sortedAdjList.at(2).getAt(2).getCost() == 100);
    }

    SECTION("Sort By Time Test"){
        Flight f1("1", "1", 300, 100, "Air");
        Flight f2("2", "2", 200, 60, "Air");
        Flight f3("3", "3", 100, 10, "Air");
        DSList<Flight> l1;
        l1.push_back(f1); l1.push_back(f3); l1.push_back(f1);
        DSList<Flight> l2;
        l2.push_back(f2); l2.push_back(f2); l2.push_back(f2);
        DSList<Flight> l3;
        l3.push_back(f3); l3.push_back(f2); l3.push_back(f1);
        FlightAdjList newAdjList;
        newAdjList.addList(l1); newAdjList.addList(l2); newAdjList.addList(l3);
        FlightAdjList sortedAdjList = newAdjList.sortByTime();

        REQUIRE(sortedAdjList.getSize() == flightAdjList.getSize());
        REQUIRE(sortedAdjList.at(0).getAt(0).getOrigin() == "3");
        REQUIRE(sortedAdjList.at(0).getAt(1).getDestination() == "2");
        REQUIRE(sortedAdjList.at(0).getAt(2).getTime() == 100);
        REQUIRE(sortedAdjList.at(1).getAt(0).getOrigin() == "2");
        REQUIRE(sortedAdjList.at(1).getAt(1).getDestination() == "2");
        REQUIRE(sortedAdjList.at(1).getAt(2).getTime() == 60);
        REQUIRE(sortedAdjList.at(2).getAt(0).getOrigin() == "1");
        REQUIRE(sortedAdjList.at(2).getAt(1).getDestination() == "3");
        REQUIRE(sortedAdjList.at(2).getAt(2).getTime() == 100);
    }
}

