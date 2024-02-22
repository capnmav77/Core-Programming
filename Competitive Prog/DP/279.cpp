// 279. Perfect Squares
// Solved
// Medium
// Topics
// Companies
// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
 

// Constraints:

// 1 <= n <= 104


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//memoization
class Solution {
private:
    int solve(int n,vector<int> &dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        int mini = INT_MAX;
        for(int i=1 ; i*i<=n ; i++){
            int perfectsq = i*i;
            int ans = 1 + solve(n-perfectsq,dp);
            mini = min(ans,mini);
        }
        return dp[n]=mini;
        
    }

public:
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};

// class Solution {
// public:
//     int numSquares(int n) {

//         vector<int> dp(n+1 , INT_MAX-10000 );
//         dp[0]=0;
//         for(int i=1 ; i<=n ; i++){
//             int limit = sqrt(i);
//             while(i-(limit*limit)>=0){
//                 dp[i] = min(dp[i],dp[i-(limit*limit)]+1);
//                 --limit;
//             }
//         }
//         return dp[n];
//     }
// };


int main(){
    Solution s;
    cout<<s.numSquares(12);
    return 0;
}