/*
                            - Number of Islands -

Given a 2d grid map of '1's (land) and '0's (water), count the number of
islands. An island is surrounded by water and is formed by connecting adjacent
lands horizontally or vertically. You may assume all four edges of the grid are
all surrounded by water.

Example 1:
Input:
11110
11010
11000
00000
Output: 1

Example 2:
Input:
11000
11000
00100
00011
Output: 3
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {

    int n, m;

    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';

        if(x < n - 1 && grid[x + 1][y] == '1') {
            dfs(grid, x + 1, y);
        }
        if(x > 0 && grid[x - 1][y] == '1') {
            dfs(grid, x - 1, y);
        }
        if(y < m - 1 && grid[x][y + 1] == '1') {
            dfs(grid, x, y + 1);
        }
        if(y > 0 && grid[x][y - 1] == '1') {
            dfs(grid, x, y - 1);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int answer = 0;
        n = grid.size();
        m = grid.front().size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == '1') {
                    ++answer;
                    dfs(grid, i, j);
                }
            }
        }

        return answer;
    }
};

int main (){
    vector<vector<char>> grid {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    assert(Solution{}.numIslands(grid) == 1);

    grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    assert(Solution{}.numIslands(grid) == 3);
}