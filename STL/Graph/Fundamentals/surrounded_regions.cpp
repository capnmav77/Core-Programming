#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();

        // Directions for moving in 4 directions
        vector<int> directions = {0, 1, 0, -1, 0};

        // Mark border-connected 'O's
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0, directions);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1, directions);
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j, directions);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j, directions);
        }

        // Convert remaining 'O's to 'X's and revert 'E's to 'O's
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'E') {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j, vector<int>& directions) {
        int m = board.size();
        int n = board[0].size();
        // Return if out of bounds or not 'O'
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
        // Mark this cell as 'E' (escaped)
        board[i][j] = 'E';

        // Explore all 4 directions
        for (int k = 0; k < 4; ++k) {
            int x = i + directions[k];
            int y = j + directions[k + 1];
            dfs(board, x, y, directions);
        }
    }
};


int main(){
    Solution s;
    vector<vector<char>> mat = {{"X","O","X","O","X","O"},{"O","X","O","X","O","X"},{"X","O","X","O","X","O"},{"O","X","O","X","O","X"}};
    s.solve(mat);
    for(auto it: mat){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}