#include<iostream>
#include<map>
using namespace std;

char findKeybyVal(map<char,int> mp, int k){
    for(auto itr:mp){
        if(itr.second == k) return itr.first;
    }
    return -1;
}

int main(){
    map<char,int> mp;
    map<char,int>::iterator itr;

    mp['a']=0;
    mp['b']=1;
    mp['c']=2;
    mp['d']=3;
    mp['e']=4;
    mp['f']=5;
    mp['g']=6;

    itr = mp.find('b');
    if(itr==mp.end()) cout << "key-value not present in map";
    else cout << itr-> first << " : " << itr->second;

    char key = findKeybyVal(mp,5);
    cout<< " Key " << key;

    return 0;
}