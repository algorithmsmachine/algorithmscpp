// List 

// sequential access
// non contigious memeory location 
// slower than vectors for traversal

#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void printllist(list<int> list){
    for(auto i=list.begin();i!=list.end();++i){
        cout << *i<< " ";
    }
    cout<<endl;
}

int main(){
    list <int> l1,l2;
    for(int i=0;i<=10;i++){
        l1.push_back(i*2);
        l2.push_back(i*3);
    }

    printllist(l1);
    printllist(l2);

    cout<<"\n Front " << l1.front();
    cout<<"\n Back " << l1.back();

    cout<< "\n pop ";
    l1.pop_front();
    l1.pop_back();
    printllist(l1);

    cout<< "\n Reverse ";
    l2.reverse();
    printllist(l2);

    cout<< "\n Sort ";
    l2.sort();
    printllist(l2);

    return 0;
}

// g++ list.cpp -o list.out
// ./list.out

// output
// 0 2 4 6 8 10 12 14 16 18 20 
// 0 3 6 9 12 15 18 21 24 27 30 

//  Front 0
//  Back 20
//  pop2 4 6 8 10 12 14 16 18 
//  Reverse 30 27 24 21 18 15 12 9 6 3 0 
//  Sort 0 3 6 9 12 15 18 21 24 27 30