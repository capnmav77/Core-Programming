// 576. Out of Boundary Paths
// Solved
// Medium
// Topics
// Companies
// Hint
// There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

// Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

 

// Example 1:


// Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
// Output: 6
// Example 2:


// Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
// Output: 12

#include<bits/stdc++.h>

using namespace std;

// class Solution {
// private: 
//     int rec(int remMove , int row, int col , int restriction , int m , int n){
//         if(remMove == -1){
//             return 0;
//         }
//         if(row<0 || col <0 || col>=n || row>=m){
//             return 1;
//         }
//         int possiblePaths = 0;
//         possiblePaths += rec(remMove-1 , row-1 , col , 2 , m , n);
//         possiblePaths += rec(remMove-1 , row , col-1 , 2 , m , n);
//         possiblePaths += rec(remMove-1 , row+1 , col , 2 , m , n);
//         possiblePaths += rec(remMove-1 , row , col+1 , 2 , m , n);
//         return possiblePaths;
//     }

// public:
//     int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
//         //vector<vector<int>> dp(m , vector<int>(n , -1));
//         return rec(maxMove , startRow , startColumn , 0 , m , n);
//     }
// };

#pragma GCC optimize("O3", "unroll-loops")
using int2=pair<int,int>;
vector<int2> moves={{1,0},{-1, 0},{0,1},{0,-1}};
const int mod=1e9+7;
class Solution {
public:
    int dp[51][51][51];
    int m, n;
    int f(int i, int j, int moveLeft){
        if (i<0 || i==m || j<0 || j==n) return 1;
        if (moveLeft==0) return 0;
        if (dp[i][j][moveLeft]!=-1) return dp[i][j][moveLeft];
        long long ans=0;
        for (auto [a, b]: moves){
            int r=i+a, c=j+b;
            ans=(ans+f(r, c, moveLeft-1))%mod;
        }
        return dp[i][j][moveLeft]=ans;
    }
    int findPaths(int m, int n, int maxMove, int Row, int Column) {
        this->m=m, this->n=n;
        memset(dp, -1, sizeof(dp));
        return f(Row, Column, maxMove);
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main()
{

    Solution s;
    cout<<s.findPaths(2,2,2,0,0);
    return 0;
}
