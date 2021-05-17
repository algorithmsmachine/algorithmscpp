// Queue 

#include <iostream>
#include <queue>
using namespace std;

void printq(queue<int> q){
    queue<int> qcopy = q;
    while(!qcopy.empty()){
        cout << " \t " << qcopy.front();
        qcopy.pop();
    }
    cout << '\n';
}

int main()
{
    queue<int> qq;
    qq.push(6);
    qq.push(4);
    qq.push(1);
    printq(qq);
  
    cout << "\n queue.size() : " << qq.size();
    cout << "\n queue.front() : " << qq.front();
    cout << "\n queue.back() : " << qq.back();
  
    cout << "\n queue.pop() ";
    qq.pop();
    printq(qq);
  
    return 0;
}

//  g++ queue.cpp -o queue.out
// ./queue.out

//output
//          6       4       1

//  queue.size() : 3
//  queue.front() : 6
//  queue.back() : 1
//  queue.pop()     4       1