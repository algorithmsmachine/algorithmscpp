//
// Created by altanai on 08/02/21.
//


/*
 * Driver.cpp
 * This is the driver for the scheduling program. It provides prompts to
 * the user and displays information.
 */
//#include "SJF.h"
//#include "SRTF.h"
//#include "ProcessRR.h"
#include "Processes.h"
#include "Roundrobin.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//main method that displays information and prompts user
int main() {
    string another;
    do {

        cout << "\n Input name of file with data: ";
        string fileName;
        getline(cin, fileName);

        ifstream infile;
        infile.open(fileName);
        if (infile.fail()) {
            cout << "ERROR: file note found!" << endl;
            break;
        }

//        cout << "\nHere are the scheduling algorithms for the file " << fileName << "." << endl;
//        cout << "\nShortest Job First (SJF)" << endl;
//        SJF sjf;
//        sjf.getFileData(fileName);
//        cout << "\nAverage Waiting Time= " << sjf.getAverageWaitingTime() << endl;
//        cout << "Average Throughput= " << sjf.getThroughput() << endl;
//        cout << "Average Turnaround Time= " << sjf.getAverageTurnaroundtime() << endl;
//        cout << "\n";

        cout << "Round Robin (RR)" << endl;
        Roundrobin rr;
        cout << "Order: ";
        rr.getFileData(fileName);
        cout << "\n Average Waiting Time= " << rr.getAverageWaitingTime() << endl;
        cout << "Average Throughput= " << rr.getThroughput() << endl;
        cout << "Average Turnaround Time= " << rr.getAverageTurnaroundtime() << endl;
        cout << "\n";

//        cout << "Shortest Remaining Time (SRTF)" << endl;
//        SRTF srtf;
//        srtf.getFileData(fileName);
//        cout << "\nAverage Waiting Time= " << srtf.getAverageWaitingTime() << endl;
//        cout << "Average Throughput= " << srtf.getThroughput() << endl;
//        cout << "Average Turnaround Time= " << srtf.getAverageTurnaroundtime() << endl;
//        cout << "\n";

        cout << "\nDo you want to test another file? y/n: ";

        getline(cin, another);

    } while (another == "y");
    cout << "\n";

}