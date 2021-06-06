#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,4,6,7,8,9,0};
    arr[2]=800;
    int arrn = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i<arrn; i++)
        cout << arr[i]<< " ";
    cout << endl;
    
    int table[3][3]= {{1,2,3},
                    {5,8,8},
                    {2,9,4}};

    table[2][0]=200;

    for (int i = 0; i <3; i++)
    {
        for (int j = 0; j<3; j++)
            cout << table[i][j]<< " ";

        cout << endl;
    }
    return 1;
}