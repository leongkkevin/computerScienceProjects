//
// Created by Kevin Leong on 10/21/20.
//

#include "catch.hpp"

#include "DSString.h"

#include "DSStack.h"
#include "FlightAdjList.h"

TEST_CASE("Stack Class", "[Stack]"){
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

        REQUIRE(stringStack.pop() == "!!!");
        REQUIRE(stringStack.getSize() == 2);
        REQUIRE(stringStack.pop() == " ");
        REQUIRE(stringStack.getSize() == 1);
        REQUIRE(stringStack.pop() == "plane");
        REQUIRE(stringStack.getSize() == 0);
        REQUIRE(stringStack.isEmpty());
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
    }
}

TEST_CASE("Adjacency List Class", "[AdjList]"){

}

