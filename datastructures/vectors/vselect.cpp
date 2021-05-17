// Selection of elements from vector with sum equal to target 

#include<iostream>
#include<vector>
using namespace std;

// Input : vector of integers , desired target
// Output : index of elements in vector with sum equal to target 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> vr;
        for(auto i=nums.begin(); i!=nums.end(); ++i ){
            // if(*i==target) {
            //     vr.push_back(*i);
            // }
            
            for(auto j=i+1; j!=nums.end(); ++j ){
                // cout<< *i << *j;
                if(((*i)+(*j))==target){
                    vr.push_back(distance(nums.begin(),i));
                    vr.push_back(distance(nums.begin(),j));
                    return vr;
                }
            }
        }
        
        
    }
};

int main(){
    vector<int> v{3,2,4};
    int t=6;
    vector<int> vr= Solution().twoSum(v,t);
    for(auto i=vr.begin();i!=vr.end();++i){
        cout<< *i << " ";
    }
}
