// 70. Climbing Stairs
// Solved
// Easy
// Topics
// Companies
// Hint
// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

#include<bits/stdc++.h>

using namespace std;

//recursion -- tle
// class Solution {

// private:
//     int rec(int n ){
//         if(n==0) return 1;
//         if(n<0) return 0;
//         int one = rec(n-1);
//         int two = rec(n-2);
//         return one + two;
//     }

// public:
//     int climbStairs(int n) {
//         return rec(n);
//     }
// };

//memoization with a hash-map
// class Solution {
// public:
//     int climbStairs(int n, unordered_map<int, int>& memo) {
//         if (n == 0 || n == 1) {
//             return 1;
//         }
//         if (memo.find(n) == memo.end()) {
//             memo[n] = climbStairs(n-1, memo) + climbStairs(n-2, memo);
//         }
//         return memo[n];
//     }

//     int climbStairs(int n) {
//         unordered_map<int, int> memo;
//         return climbStairs(n, memo);
//     }
// };

//normal dp with tabulation
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n==0){
//             return 0;
//         }
//         if(n==1){
//             return 1;
//         }
//         vector<int> dp(n);
//         dp[0] = 1;
//         dp[1] = 2;
//         for(int i= 2 ; i<n ; i++){
//             dp[i] = dp[i-1]+dp[i-2];
//         }
//         return dp[n-1];
//     }
// };

// dp with space optimization

class Solution {
public:
    int climbStairs(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int i = 1;
        int j = 2;
        for(int k= 2 ; k<n ; k++){
            int temp = i+j;
            i=j; 
            j=temp;
        }
        return j;
    }
};


int main()
{
    Solution s;
    cout<<s.climbStairs(3);
    return 0;
}