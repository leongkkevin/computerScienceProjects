#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include <iostream>

#include "FlightPlanner.h"

using namespace std;

int runCatchTest(int argc, char* const argv[]){
    return Catch::Session().run(argc, argv);
}

int main(int argc, char** argv){
    if(argc == 1){
        return runCatchTest(argc, argv);
    }

    ifstream inFlightFile(argv[1]);
    ifstream inFile(argv[2]);
    ofstream outFule(argv[3]);

    runFlightPlanner(inFlightFile, inFile);


//    std::ofstream outputstream(argv[2]);
//    outputstream << "Hello, World!" << std::endl;
//    outputstream.close();
//    std::cout << "Hello and wrote sample output file." << std::endl;

    return 0;
}

