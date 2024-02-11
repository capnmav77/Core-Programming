#include<iostream>
#include<bits/stdc++.h>

using namespace std;


// Memoization
// class Solution {
// int MOD = 1e9 + 7;
// private:

//     void display(vector<vector<int>> & dp ,int n){
//         for(int i=0 ; i<n ; ++i){
//             for(int j=0 ; j<n ; ++j){
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//     }


// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         //find all possible subarrays
//         //add it to the sum of the final product
//         int n = arr.size();
//         vector<vector<int>> dp(n , vector<int>(n,-1));
//         int sum = 0;

//         for(int i=0 ; i<n ; ++i){
//             dp[0][i] = arr[i];
//             sum += dp[0][i];
//         }
        
//         for(int i=1 ; i<n ; i++){
//             for(int j=0 ; j<n ; j++){
//                 if(i+j<n){
//                     dp[i][j] = min(dp[i-1][j] ,arr[i+j]);
//                     sum = (sum + dp[i][j])%MOD;
//                 }
//             }
//         }

//         //display(dp,n);
//         return sum;
//     }
// };

// class Solution {
// int MOD = 1e9 + 7;
// private:

//     void display(vector<vector<int>> & dp ,int n){
//         for(int i=0 ; i<n ; ++i){
//             for(int j=0 ; j<n ; ++j){
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//     }


// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         //find all possible subarrays
//         //add it to the sum of the final product
//         int n = arr.size();
//         //vector<vector<int>> dp(n , vector<int>(n,-1));
//         vector<int> prev = arr ;
//         vector<int> curr (n , -1);
//         int sum = 0;
        
//         for(int i=0 ; i<n ; i++){
//             for(int j=0 ; j<n-i ; j++){
//                 if(i+j<n){
//                     curr[j] = min(prev[j] ,arr[i+j]);
//                     sum = (sum + curr[j])%MOD;
//                 }
//             }
//             prev = curr;
//         }

//         //display(dp,n);
//         return sum;
//     }
// };

#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size(), mod=1e9+7;
        vector<long long> dp(n, -1); // dp[i]=sum of subarrays ending at i
        vector<int> stack;
        long long ans=0;
        for(int i=0; i<n; i++){
            //monotonic increasing stack storing the index
            while(!stack.empty() && arr[i]<=arr[stack.back()])
                stack.pop_back();
            if (!stack.empty()){
                int j=stack.back();
                dp[i]=dp[j]+arr[i]*(i-j);
            }
            else dp[i]=arr[i]*(i+1);
            stack.push_back(i);
            ans=(ans+dp[i])%mod;
        }
        return ans;      
    }
};

int main()
{
    Solution s;
    vector<int> arr = {3,1,2,4};
    cout<<s.sumSubarrayMins(arr)<<endl;
    return 0;
}