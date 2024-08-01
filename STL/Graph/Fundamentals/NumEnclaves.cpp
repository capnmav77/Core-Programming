#include<iostream>
#include<bits/stdc++.h>

using namespace std; 
class Solution {
public:
    int dir[5] = {0,1,0,-1,0};

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;

        // Step 1: Enqueue all boundary '1's and mark them as '2'
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && (i == 0 || i == n-1 || j == 0 || j == m-1)) {
                    q.push({i, j});
                    grid[i][j] = 2; // Mark as visited
                }
            }
        }

        // Step 2: Perform BFS to mark all connected land cells from the boundary
        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i];
                int ny = y + dir[i + 1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                    q.push({nx, ny});
                    grid[nx][ny] = 2; // Mark as visited
                }
            }
        }

        // Step 3: Count remaining '1's that are not connected to the boundary
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ++count;
                }
            }
        }

        return count;
    }
};
