#include<iostream>
#include<vector>
using namespace std ;

vector<int> makeVector(int n){
    vector<int>v;
    for(int i=1;i<=10;i++)
        v.push_back(i);
    return v;
}

int main(){
    vector<int> v2=makeVector(10);
    // for(auto i=v2.begin();i!=v2.end();++i){
    //     cout << *i << " ";
    // }

    //print 2nd to second last element only 
    for(auto i= v2.begin()+1;i!=v2.end()-1;++i){
        cout << *i << " ";
    }

    //print 2nd to second last element only 
    for(auto i= v2.begin()+1;i!=v2.end()-1;++i){
        cout << *i << " ";
    }

    return 0;
}