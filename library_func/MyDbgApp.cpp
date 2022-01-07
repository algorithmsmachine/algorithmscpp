#include <list>
#include <iostream>

using namespace std;

void doWork()
{
    list <int> c1;

    c1.push_back(10);
    c1.push_back(20);

    const list <int> c2 = c1;
    const int &i = c2.front();
    const int &j = c2.front();
    cout << "The first element is " << i << endl;
    cout << "The second element is " << j << endl;

}

int main()
{
    doWork();
} 