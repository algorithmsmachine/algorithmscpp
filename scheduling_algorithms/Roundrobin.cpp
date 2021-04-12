// Round Robin
// This is the implementation of the Round Robin scheduling algorithm.
//
// Created by altanai on 08/02/21.

#include <string>
#include <iostream>
#include "Processes.h"
#include <fstream>
#include <list>
#include <iterator>
#include <typeinfo>
#include <queue>
#include "Roundrobin.h"


//Constructor
Roundrobin::Roundrobin() {
    lastArrival = -1;
    CPUtimer = -1; //CPU time hasn't started
    sumTurnaroundTime = 0;
    sumWaitingTime = 0;
    countOfProcesses = 0; //FIXME
    countTotalTime = 0;
    newArrival = -1;

}

//gets the data from the file and puts them into a list of Process objects
void Roundrobin::getFileData(string fileName) {
    //print out all values from file
    ifstream afile;
    string line;
    afile.open(fileName); //fixme
    list <Processes> alist;
    //make each line a process
    while (afile >> line) {
        countOfProcesses++;
        alist.push_back(makeProcess(line));
    }
    newArrival = countOfProcesses;
    //do an array of size lastArrival and fill it with the processes
    putProcessInArray(alist);
    list<Processes>::iterator itr;

    //make a min heap
    //set up logic of putting in min heap if the time is equal or less

}

//puts all the processes in an array and then
//uses a minqueue to process them.
void Roundrobin::putProcessInArray(list <Processes> alist) {
    //make array of lists
    list <Processes> allProcesses[lastArrival + 1];
    //fill array with empty list
    for (int i = 0; i < lastArrival + 1; i++) {
        list <Processes> temp;
        allProcesses[i] = temp;
    }

    //put these processes in an array based on arrival time
    list<Processes>::iterator itr;
    for (itr = alist.begin(); itr != alist.end(); ++itr) {
        allProcesses[itr->getArrivalTime()].push_back(*itr);
    }


    //initialize a min heap and put all the processes that start at 0
    int beg = 0;
    CPUtimer++;
    priority_queue <Processes> q;
    while (CPUtimer <= lastArrival) {
        for (int i = beg; i <= CPUtimer; i++) {
            if (allProcesses[i].empty()) {
                //do nothing
            } else {
                //add it to the queue
                list<Processes>::iterator itr2;
                for (itr2 = allProcesses[i].begin(); itr2 != allProcesses[i].end(); ++itr2) {
                    q.push(*itr2);
                }
            }
        }
        Processes tempP = q.top();
        tempP.printValues();
        beg = CPUtimer + 1;
        CPUtimer = CPUtimer + 1;
        //subtract one unit of time from top
        tempP.CPUburst = tempP.CPUburst - 1;
        //pop, if greater than zero add back in, if 0 don't add
        if (tempP.CPUburst == 0) {
            sumTurnaroundTime = sumTurnaroundTime + (CPUtimer - tempP.arrivalTime);
            countTotalTime = CPUtimer;
            int turnaroundtime = CPUtimer - tempP.arrivalTime;
            int waitingtime = turnaroundtime - tempP.tempCPUburst;
            sumWaitingTime = sumWaitingTime + waitingtime;
            q.pop();
        } else {
            q.pop();
            newArrival = CPUtimer;
            tempP.priority = -1; //appear first
            tempP.tempArrivalTime = newArrival;
            q.push(tempP);
        }
    }

    //pop remaining
    while (!q.empty()) {
        Processes tempP = q.top();
        tempP.printValues();
        CPUtimer = CPUtimer + 1;
        //subtract one unit of time from top
        tempP.CPUburst = tempP.CPUburst - 1;
        //pop, if greater than zero add back in, if 0 don't add
        if (tempP.CPUburst == 0) {
            sumTurnaroundTime = sumTurnaroundTime + (CPUtimer - tempP.arrivalTime);
            countTotalTime = CPUtimer;
            int turnaroundtime = CPUtimer - tempP.arrivalTime;
            int waitingtime = turnaroundtime - tempP.tempCPUburst;
            sumWaitingTime = sumWaitingTime + waitingtime;
            q.pop();
        } else {
            q.pop();
            newArrival = CPUtimer;
            tempP.priority = -1;
            tempP.tempArrivalTime = newArrival;
            q.push(tempP);
        }
    }
    return;
}

//goes through text and gets the data from the file
//to make a Process object
Processes Roundrobin::makeProcess(string line) {
    int commas = 0;
    string v1 = "";
    string v2 = "";
    string v3 = "";
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            commas++;
        } else {
            if (commas == 0) {
                v1 = v1 + line.at(i);
            } else if (commas == 1) {
                v2 = v2 + line.at(i);
            } else {
                v3 = v3 + line.at(i);
            }
        }

    }
    Processes p(stoi(v1), stoi(v2), stoi(v3));
    //find out last arrival time;
    if (stoi(v3) > lastArrival) {
        lastArrival = stoi(v3);
    }
//	p.printValues();
    return p;
}

//calculates and returns the turnaroundtime
double Roundrobin::getAverageTurnaroundtime() {
    double ans = (double(sumTurnaroundTime) / double(countOfProcesses));
    //FIXME set precision higher
    return ans;
}

//calculates and returns the averagewait time
double Roundrobin::getAverageWaitingTime() {
    double ans = (double(sumWaitingTime) / double(countOfProcesses));
    //FIXME set precision higher
    return ans;
}

//calculates and returns the throughput
double Roundrobin::getThroughput() {
    double ans = (double(countOfProcesses) / double(countTotalTime));
    return ans;
}
