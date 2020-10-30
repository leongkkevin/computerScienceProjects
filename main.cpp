#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

//../flightData.txt ../input.txt ../output.txt

#include <iostream>
#include <iomanip>

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
    ofstream outFile(argv[3]);

    runFlightPlanner(inFlightFile, inFile, outFile);

    inFlightFile.close();
    inFile.close();
    outFile.close();

    return 0;
}

