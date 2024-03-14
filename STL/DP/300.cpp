// Given an integer array nums, return the length of the longest strictly increasing 
// subsequence
// .

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1


#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>


using namespace std;



class Solution {
private: 
    void display(vector<vector<int> > dp){
        for(int i=0 ; i<dp.size() ; i++){
            for(int j=0 ; j<dp[0].size() ; j++){
                cout<<dp[i][j]<<"   ";
            }
            cout<<endl;
        }
    }

    int topdown(int index, int prev_ind , int n , vector<int> nums , vector<vector<int> > & dp){
        if(index == n){
            return 0; 
        }
        if(dp[index][prev_ind+1] != -1){
            return dp[index][prev_ind+1];
        }

        int len = topdown(index+1 , prev_ind , n , nums , dp);

        if(prev_ind == -1 || nums[index]>nums[prev_ind]){
            len = max(len , 1 + topdown(index+1 , index , n , nums , dp));
        }
        return dp[index][prev_ind+1] = len;
    }

    int bottomup(vector<int>& nums){
        if(nums.empty()){
            return 0;
        }
        int n = nums.size();
        vector<int> dp(n , 1);

        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i] , dp[j]+1);
                }
            }
        }
        int max_len = 0;
        for(int i=0 ; i<n ; i++){
            max_len = max(max_len , dp[i]);
        }
        return max_len;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> dp(n , vector<int>(n,-1));
        // int res = topdown(0,-1,n,nums , dp);
        // display(dp);
        int res = bottomup(nums);
        return res; 
    }
};


int main()
{
    Solution s;
    const size_t N = 8;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout<<s.lengthOfLIS(nums);
    return 0;
}


