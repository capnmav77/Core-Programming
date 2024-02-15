// 931. Minimum Falling Path Sum
// Solved
// Medium
// Topics
// Companies
// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

// Example 1:


// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum as shown.


#include<bits/stdc++.h>

using namespace std;


// class Solution {
// private: 
//     int rec(int i , int j  , vector<vector<int>>& matrix, int n){
//         if(i>=n){
//             return 0;
//         }
//         if(j<0 || j>=n){
//             return INT_MAX;
//         }
//         int mi1nval = INT_MAX;
//         for(int k=0 ; k<3 ; k++){ 
//             minval = min(minval , rec(i+1 , j+k-1,matrix,n));
//         }
//         return matrix[i][j]+minval;
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int mini = INT_MAX;
//         for(int i=0 ; i<n ; i++){
//             mini = min(mini , rec(0,i,matrix,n));
//         }
//         return mini;
//     }
// };

//memoization - tle on the last test case LMAO
// class Solution {
// private: 
//     int rec(int i , int j  , vector<vector<int>>& matrix, int n , vector<vector<int>> & dp){
//         if(i>=n){
//             return 0;
//         }
//         if(j<0 || j>=n){
//             return INT_MAX;
//         }
//         if(dp[i][j]!= -1){
//             return dp[i][j];
//         }
//         int minval = INT_MAX;
//         for(int k=0 ; k<3 ; k++){ 
//             minval = min(minval , rec(i+1 , j+k-1,matrix,n,dp));
//         }
//         return dp[i][j] = matrix[i][j]+minval;
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int> > dp(n , vector<int>(n,-1));
//         int mini = INT_MAX;
//         for(int i=0 ; i<n ; i++){
//             mini = min(mini , rec(0,i,matrix,n,dp));
//         }
//         return mini;
//     }
// };

// class Solution {
// private: 
//     int rec(int i , int j  , vector<vector<int>>& matrix, int n , vector<vector<int>> & dp){
//         if(i>=n){
//             return 0;
//         }
//         if(j<0 || j>=n){
//             return INT_MAX;
//         }
//         if(dp[i][j]!= -1){
//             return dp[i][j];
//         }
//         int minval = INT_MAX;
//         for(int k=0 ; k<3 ; k++){ 
//             minval = min(minval , rec(i+1 , j+k-1,matrix,n,dp));
//         }
//         return dp[i][j] = matrix[i][j]+minval;
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int> > dp(n , vector<int>(n,0));
        
//         for(int i=0 ; i<n ; i++){
//             dp[0][i] = matrix[0][i];
//         }

//         for(int i=1 ; i<n ; i++){
//             for(int j=0 ; j<n ; j++){

//                 int down = dp[i-1][j] + matrix[i][j];

//                 int leftdiag  = INT_MAX;
//                 if(j-1>=0){
//                     leftdiag = matrix[i][j] + dp[i-1][j-1];
//                 }

//                 int rightdiag = INT_MAX;
//                 if(j+1<n){
//                     rightdiag = matrix[i][j] + dp[i-1][j+1];
//                 }

//                 dp[i][j] = min(down , min(leftdiag , rightdiag));
//             }
//         }
//         int mini = INT_MAX;
//         for(int i=0 ; i<n ; i++){
//             mini = min(mini , dp[n-1][i]);
//         }
        
//         return mini;
//     }
// }; 


//space optimization 
// class Solution {
// private: 
//     int rec(int i , int j  , vector<vector<int>>& matrix, int n){
//         if(i>=n){
//             return 0;
//         }
//         if(j<0 || j>=n){
//             return INT_MAX;
//         }
//         int mi1nval = INT_MAX;
//         for(int k=0 ; k<3 ; k++){ 
//             minval = min(minval , rec(i+1 , j+k-1,matrix,n));
//         }
//         return matrix[i][j]+minval;
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int mini = INT_MAX;
//         for(int i=0 ; i<n ; i++){
//             mini = min(mini , rec(0,i,matrix,n));
//         }
//         return mini;
//     }
// };

//memoization - tle on the last test case LMAO
// class Solution {
// private: 
//     int rec(int i , int j  , vector<vector<int>>& matrix, int n , vector<vector<int>> & dp){
//         if(i>=n){
//             return 0;
//         }
//         if(j<0 || j>=n){
//             return INT_MAX;
//         }
//         if(dp[i][j]!= -1){
//             return dp[i][j];
//         }
//         int minval = INT_MAX;
//         for(int k=0 ; k<3 ; k++){ 
//             minval = min(minval , rec(i+1 , j+k-1,matrix,n,dp));
//         }
//         return dp[i][j] = matrix[i][j]+minval;
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int> > dp(n , vector<int>(n,-1));
//         int mini = INT_MAX;
//         for(int i=0 ; i<n ; i++){
//             mini = min(mini , rec(0,i,matrix,n,dp));
//         }
//         return mini;
//     }
// };

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n,0);
        vector<int> curr(n,0);
        
        for(int i=0 ; i<n ; i++){
            prev[i] = matrix[0][i];
        }

        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){

                int down = prev[j] + matrix[i][j];

                int leftdiag  = INT_MAX;
                if(j-1>=0){
                    leftdiag = matrix[i][j] + prev[j-1];
                }

                int rightdiag = INT_MAX;
                if(j+1<n){
                    rightdiag = matrix[i][j] + prev[j+1];
                }

                curr[j] = min(down , min(leftdiag , rightdiag));
            }
            prev = curr;
        }
        int mini = INT_MAX;
        for(int i=0 ; i<n ; i++){
            mini = min(mini , prev[i]);
        }
        
        return mini;
    }
}; 

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    cout<<s.minFallingPathSum(matrix)<<endl;
    return 0;
}