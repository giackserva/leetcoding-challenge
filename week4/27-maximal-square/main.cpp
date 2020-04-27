/*
                            - Maximal Square -

Given a 2D binary matrix filled with 0's and 1's, find the largest square
containing only 1's and return its area.

Example:
Input:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Output: 4
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
    int trySquare(const vector<vector<char>>& matrix, int x, int y, int n, int m, int minSize) {
        auto isValid = [&](int i, int j) {
            return 0 <= i && i < n && 0 <= j && j < m;
        };

        for(int i = 0; i < minSize; ++i) {
            for(int j = 0; j < minSize; ++j) {
                if(!isValid(x + i, y + j) || matrix[x + i][y + j] == '0') {
                    return minSize;
                }
            }
        }

        int newSize = minSize;

        while(true) {
            int trySize = newSize + 1;
            for(int i = 0; i < trySize; ++i) {
                if(!isValid(x + i, y + trySize - 1) || matrix[x + i][y + trySize - 1] == '0') {
                    return newSize;
                }
            }

            for(int i = 0; i < trySize; ++i) {
                if(!isValid(x + trySize - 1, y + i) || matrix[x + trySize - 1][y + i] == '0') {
                    return newSize;
                }
            }
            newSize = trySize;
        }

        return newSize;
    }
public:
    int maximalSquare(const vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix.front().empty()) {
            return 0;
        }
        const int n = matrix.size();
        const int m = matrix.front().size();

        int answer = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(matrix[i][j] == '1') {
                    answer = max(answer, trySquare(matrix, i, j, n, m, answer));
                }
            }
        }
        return answer * answer;
    }
};

int main() {
    vector<vector<char>> matrix {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    assert(Solution{}.maximalSquare(matrix) == 4);

    matrix = vector<vector<char>> {
        {'1', '0', '1', '1', '1'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    assert(Solution{}.maximalSquare(matrix) == 9);

    matrix = vector<vector<char>> {
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'}
    };
    assert(Solution{}.maximalSquare(matrix) == 16);
}