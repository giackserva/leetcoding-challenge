/*
                            - Minimum Path Sum -

Given a m x n grid filled with non-negative numbers, find a path from top left
to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid.front().empty()) {
            return 0;
        }
        const int m = grid.size();
        const int n = grid.front().size();

        // first column
        for(int i = 1; i < m; ++i) {
            grid[i][0] += grid[i-1][0];
        }

        // first row
        for(int i = 1; i < n; ++i) {
            grid[0][i] += grid[0][i-1];
        }

        // everything else
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
            }
        }

        return grid[m-1][n-1];
    }
};

int main (){
    vector<vector<int>> grid {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    assert(Solution{}.minPathSum(grid) == 7);
}