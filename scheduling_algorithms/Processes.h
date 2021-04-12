//
// Created by altanai on 08/02/21.
//

#ifndef ALGORITHMSCPP_PROCESSES_H
#define ALGORITHMSCPP_PROCESSES_H


class Processes {
private:


public:
    int priority; //at first same as jobID but then -1
    int terminationTime;
    int arrivalTime;
    int tempArrivalTime;
    int jobID;
    int CPUburst;
    int tempCPUburst;

    Processes(int, int, int);

    //bool operator>(const Process &p1, const Process &p2);
    void printValues();

    int getArrivalTime();

    bool operator<(const Processes &p1) const;

};


#endif //ALGORITHMSCPP_PROCESSES_H
