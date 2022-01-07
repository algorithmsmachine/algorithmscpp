// min max sorting
// both way selection sorting

// 1. find max in D&C
// 2. Find min in D&C
// 3. swap with first and last items 

#include<iostream>
using namespace std;

// Dand C min max not workig 
int maximum_index(int arr[],int l,int r){
   if (l>=r)  return l;
   int m=(l+r) / 2;
   int u= maximum_index(arr,l,m); 
   int v= maximum_index(arr,m+1,r); 
   return (arr[u]> arr[v])? u: v;  
}

int minimum_index(int arr[],int l,int r){
   if (l>=r)  return l;
   int m=(l+r) / 2;
   int u= minimum_index(arr,l,m);
   int v= minimum_index(arr,m+1,r);
   return (arr[u]< arr[v])? u: v;    
}

void minmaxsorting(int arr[], int n){
    
    for( int i=0,j=n-1;i<j;i++,j--){

        cout << i << " " << j << endl;
        int maxi= maximum_index(arr,i,j);
        int mini= minimum_index(arr,i,j);
        cout << "\n maximum " << arr[maxi] << " minimum "<< arr[mini] <<endl;

        // int maxi=i, mini=i;
        // int min =arr[mini],max=arr[maxi]; 
        // for (int k = i; k <= j; k++)  {
        //     if (arr[k] > max) {
        //         max = arr[k];
        //         maxi = k;
        //     } else if (arr[k] < min) {
        //         min = arr[k];
        //         mini = k;
        //     }
        // }
        swap(arr[i], arr[mini]); // put min at first position 
        
        if(arr[mini]>=arr[maxi])
            swap(arr[j], arr[mini]); // shift max
        else
            swap(arr[j], arr[maxi]); // put max at last position
    }
}
int main(){
    int arr[]={20,4,15,6,17,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    minmaxsorting(arr,n);
    for(auto x :arr)
        cout << x<< " ";
}