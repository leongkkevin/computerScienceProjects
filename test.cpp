//
// Created by Kevin Leong on 10/21/20.
//

#include "catch.hpp"

#include "DSString.h"

#include "DSStack.h"
#include "DSAdjList.h"

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
}

//TEST_CASE("Adjacency List Class", "[AdjList]"){
//    DSAdjList<int> intAdjList;
//    intAdjList.add(1);
//    intAdjList.add(10);
//    intAdjList.add(100);
//
//    DSAdjList<int> intAdjList2(2);
//    intAdjList2.add(20);
//    intAdjList2.add(200);
//
//
//    SECTION("Find Test"){
//        REQUIRE(intAdjList.find(1) == 0);
//        REQUIRE(intAdjList.find(10) == 1);
//        REQUIRE(intAdjList.find(100) == 2);
//        REQUIRE(intAdjList.find(50) == -1);
//
//        REQUIRE(intAdjList2.find(2) == 0);
//        REQUIRE(intAdjList2.find(20) == 1);
//        REQUIRE(intAdjList2.find(200) == 2);
//        REQUIRE(intAdjList2.find(50) == -1);
//    }
//
//    SECTION("Add by Index Test"){
//        intAdjList.addToListNum(0, 2);
//        REQUIRE(intAdjList.listSize(0) == 2);
//        intAdjList.addToListNum(1, 11);
//        REQUIRE(intAdjList.listSize(1) == 2);
//        intAdjList.addToListNum(2, 101);
//        REQUIRE(intAdjList.listSize(2) == 2);
//    }
//
//    SECTION("Add by Name Test"){
//        intAdjList2.addToListName(2, 3);
//        REQUIRE(intAdjList2.listSize(0) == 2);
//        intAdjList2.addToListName(20, 21);
//        REQUIRE(intAdjList2.listSize(1) == 2);
//        intAdjList2.addToListName(200, 201);
//        REQUIRE(intAdjList2.listSize(2) == 2);
//    }
//
//    SECTION("AddList Test"){
//        DSList<int> intList1;
//        intList1.push_back(1000);
//        intList1.push_back(10000);
//        intAdjList.addList(intList1);
//        REQUIRE(intAdjList.atName(1000, 0) == 1000);
//        REQUIRE(intAdjList.atNum(3, 1) == 10000);
//        REQUIRE(intAdjList.listSize(3) == 2);
//    }
//
//    SECTION("List Test"){
//
//    }
//}

