#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v1;
    for( int i=5;i<=10;i++) 
        v1.push_back(i);

    // iterator
    for( auto i=v1.begin();i!=v1.end();++i) 
        cout<<*i << " ";
    cout<< endl;

    // reverse iterator
    for( auto i=v1.rbegin();i!=v1.rend();++i) 
        cout<<*i << " ";
    cout<< endl;

    // constant iterator 
    for( auto i=v1.cbegin();i!=v1.cend();++i) 
        cout<<*i << " ";
    cout<< endl;

    // reverse constant iterator
    for( auto i=v1.crbegin();i!=v1.crend();++i) 
        cout<<*i << " ";
    cout<< endl;

    cout<<"Empty " << v1.empty()<< endl;
    cout<<"Size "<< v1.size()<< endl;
    cout<<"Max size "<< v1.max_size() << endl;
    cout<<"Capacity "<< v1.capacity() << endl;

    v1.resize(3);
    cout<<"Resize to 3 "<<v1.size() <<endl;
    for (auto it = v1.begin(); it != v1.end(); it++)
        cout<< *it << " ";

    v1.shrink_to_fit();
    cout<<"Shrink to cpacity "<<v1.capacity()<<endl;
    for (auto it = v1.begin(); it != v1.end(); it++)
        cout<< *it << " ";

    cout<<"Refernce operator "<< v1[2] <<endl;;
    cout<<"At operator "<< v1.at(2)<<endl;
    cout<<"Front "<<v1.front() <<" Back "<< v1.back()<<endl;
    int * pos = v1.data();
    cout<<"Position of first " << *pos; 

    // v1.reserve();

    //assign 
    v1.assign(3,10);
    for (auto it = v1.begin(); it != v1.end(); it++)
        cout << *it << " ";

    v1.push_back(87);
    v1.push_back(92);
    v1.pop_back();
    for (auto it = v1.begin(); it != v1.end(); it++)
        cout << *it << " ";

    v1.insert(v1.begin(),100);
    cout<<"\n First element is: " << v1[0];

    v1.erase(v1.begin());
    cout<<"\n First element is: " << v1[0];

    // v1.swap();
    // v1.emplace()
    // v1.emplace_back()

    v1.clear();
    cout<<"Empty " << v1.empty()<< endl;
    cout<<"Size "<< v1.size()<< endl;
}