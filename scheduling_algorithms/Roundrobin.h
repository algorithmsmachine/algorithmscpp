//
// Created by altanai on 08/02/21.
//

#ifndef ALGORITHMSCPP_ROUNDROBIN_H
#define ALGORITHMSCPP_ROUNDROBIN_H

#include <string>
#include <list>
#include "Processes.h"
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

class Roundrobin {

private:
    int lastArrival;
    int CPUtimer;
public :
    int newArrival;
    int sumTurnaroundTime;
    int sumWaitingTime;
    int countOfProcesses;
    int countTotalTime;

    //Constructor
    Roundrobin();

    //gets the data from the file and puts them into
    //a list of Process objects
    void getFileData(string);

    //goes through text and gets the data from the file
    //to make a Process object
    Processes makeProcess(string s);

    //puts all the processes in an array and then uses a minqueue to process them.
    void putProcessInArray(list <Processes> p);

    //calculates and returns the turn around time
    double getAverageTurnaroundtime();

    //calculates and returns the average wait time
    double getAverageWaitingTime();

    //calculates and returns the throughput
    double getThroughput();
};


#endif //ALGORITHMSCPP_ROUNDROBIN_H
