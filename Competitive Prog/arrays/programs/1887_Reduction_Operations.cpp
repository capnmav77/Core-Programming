#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
private:
    void display(vector<int>& nums , int n){
        for(int i=0 ; i<n ; i++){
            cout<<nums[i]<<" ";
        }
    }

public:

    int reductionOperations(vector<int>& nums) {
        //vars:
        int n = nums.size();
        int count = 0;

        //sort to traverse in reverse order
        sort(nums.begin(),nums.end());

        //start from the end 
        for( int i=n-1 ; i>0 ; i--){
            if(i>0 && nums[i-1]==nums[i]){
                //do nothing
            }
            else{
                count = count+(n-i-1)+1;
            }
        }
        return count;
    }
};


int main(){
    //vars:
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0 ; i<n ; i++){
        cin>>nums[i];
    }

    //display
    Solution s;
    cout<<s.reductionOperations(nums);
    return 0;
}


// Input:
// 3 1 2 3 
// Output:
// 3