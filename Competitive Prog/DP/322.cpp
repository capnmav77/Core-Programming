// 322. Coin Change
// Solved
// Medium
// Topics
// Companies
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0


#include<bits/stdc++.h>

using namespace std;


// class Solution {
// public:
// int solve(vector<int>& coins,int i, int amount,vector<vector<int>> &dp){
//     if(amount==0)
//         return 0;
//     if(amount<0 || i>=coins.size())
//         return INT_MAX;
//     if(dp[i][amount]!=-1)
//         return dp[i][amount];
//     int skip = solve(coins, i+1, amount,dp);
//     int not_skip = solve(coins,i, amount-coins[i],dp);
//     if(not_skip==INT_MAX)
//         not_skip=INT_MAX-1;
//     return dp[i][amount]=min(skip,1+not_skip);
// }
// int coinChange(vector<int>& coins, int amount) {
//     vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
//     int res = solve(coins, 0, amount,dp);
//     return res==INT_MAX?-1:res;
// }
// };

class Solution{
bool check(vector<int>& coins, short index, int cnt, int target){
        long sum = (long) coins[index]*cnt;
        if (sum==target) return true;
        else if (sum > target) {
            if (index == 0) return false; //when only one coin then no need to go further as long as we didn't get true 
            
            for (short i = cnt; i>0; i--){
                long take = target - (long)coins[index]*(cnt-i);
                if (take < 0) break;
                int r =  take;
                if (check(coins, index-1, i, r)) return true;    
            }
        }
        return false;
    }
    
public:
    int coinChange(vector<int>& coins, int amt) {
        if (amt&1){
            short i=0;
            for (; i<coins.size(); i++){
                if (coins[i]&1) break;
            }    
            if (i==coins.size()) return -1;
        }
    
        sort(coins.begin(), coins.end());
        int best = amt/coins.back(); //how many times the biggest element is in the target - the smallest number
        int worst = amt/coins.front(); //how many times the smallest element is in the target - the biggest number
        
        for(short i=best; i<=worst;i++){ //now we know the interval -- the smallest number < i < the biggest number
            if (check(coins, coins.size()-1, i, amt)) return i;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout<<s.coinChange(coins,amount)<<endl;
    return 0;
}