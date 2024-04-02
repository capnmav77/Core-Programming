// 2966. Divide Array Into Arrays With Max Difference
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an integer array nums of size n and a positive integer k.

// Divide the array into one or more arrays of size 3 satisfying the following conditions:

// Each element of nums should be in exactly one array.
// The difference between any two elements in one array is less than or equal to k.
// Return a 2D array containing all the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.

 

// Example 1:

// Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
// Output: [[1,1,3],[3,4,5],[7,8,9]]
// Explanation: We can divide the array into the following arrays: [1,1,3], [3,4,5] and [7,8,9].
// The difference between any two elements in each array is less than or equal to 2.
// Note that the order of elements is not important.
// Example 2:

// Input: nums = [1,3,3,2,7,3], k = 3
// Output: []
// Explanation: It is not possible to divide the array satisfying all the conditions.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int n= nums.size();
        vector<vector<int>> ans;

        if(n<3) return ans;

        vector<int> temp;   
        for(int i=0 ; i<n ; i++){
            if(i%3 == 0 && i>2){
                if(temp[2]-temp[0]>k){
                    ans.clear();
                    return ans;
                }
                //cout<<temp.begin()<<endl;
                ans.push_back(temp);
                temp.clear();
            }
            temp.push_back(nums[i]);
            if(i%3 != 0){
                if(temp[(i)%3] - temp[(i-1)%3]>k){
                    ans.clear();
                    return ans;
                }
            }
        }
        if(temp[2] - temp[0]>k){
            ans.clear();
            return ans;
        }
        ans.push_back(temp);
        return ans; 
    }
};


int main()
{
    Solution s;
    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    int k = 2;
    vector<vector<int>> ans = s.divideArray(nums , k);
    for(int i=0 ; i<ans.size() ; i++){
        for(int j=0 ; j<ans[i].size() ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}