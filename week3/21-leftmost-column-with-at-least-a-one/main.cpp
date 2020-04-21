/*
                - Leftmost Column with at Least a One -
                (This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1. For each individual row of
the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index
(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix
using a BinaryMatrix interface:

BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y)
(0-indexed).

BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the
matrix is n * m.

Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong
Answer. Also, any solutions that attempt to circumvent the judge will result in
disqualification.

For custom testing purposes you're given the binary matrix mat as input in the
following four examples. You will not have access the binary matrix directly.

Example 1:
Input: mat = [[0,0],[1,1]]
Output: 0

Example 2:
Input: mat = [[0,0],[0,1]]
Output: 1

Example 3:
Input: mat = [[0,0],[0,0]]
Output: -1

Example 4:
Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1

Constraints:
1 <= mat.length, mat[i].length <= 100
mat[i][j] is either 0 or 1.
mat[i] is sorted in a non-decreasing way.
*/

#include<bits/stdc++.h>

using namespace std;

class BinaryMatrix {
    vector<vector<int>> matrix;
  public:
    BinaryMatrix(const vector<vector<int>>& matrix) : matrix(matrix){};
    int get(int x, int y) {
        return matrix[x][y];
    };
    vector<int> dimensions() {
        return vector<int>{(int)matrix.size(), (int)matrix.front().size()};
    }
};

class Solution {

    int findFirstOneForRow(BinaryMatrix& binaryMatrix, int row, int m) {
        if(m == 1) {
            if(binaryMatrix.get(row, 0) == 1) {
                return 0;
            }
            return -1;
        }
        int b = 0, e = m - 1;

        while(b <= e) {
            const int middle = b + (e - b) / 2;
            const int curr = binaryMatrix.get(row, middle);
            const bool isOne = curr == 1;
            if(isOne && (middle == 0 || binaryMatrix.get(row, middle - 1) == 0)) {
                return middle;
            }
            if(isOne) {
                e = middle - 1;
            } else {
                b = middle + 1;
            }
        }

        return -1;
    }
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        const vector<int> dimensions = binaryMatrix.dimensions();
        const int n = dimensions[0];
        const int m = dimensions[1];
        if(m == 0 || n == 0) return -1;

        int answer = -1;
        // for each row, find first 1
        for(int i = 0; i < n; ++i) {
            const int curr = findFirstOneForRow(binaryMatrix, i, m);
            if(answer == -1) answer = curr;
            else if(curr != -1) answer = min(answer, curr);
        }
        return answer;
    }
};

int main() {
    BinaryMatrix matrix{{{0,0},{1,1}}};
    assert(Solution{}.leftMostColumnWithOne(matrix) == 0);

    matrix = BinaryMatrix{{{0,0},{0,1}}};
    assert(Solution{}.leftMostColumnWithOne(matrix) == 1);

    matrix = BinaryMatrix{{{0,0},{0,0}}};
    assert(Solution{}.leftMostColumnWithOne(matrix) == -1);

    matrix = BinaryMatrix{{{0,0,0,1},{0,0,1,1},{0,1,1,1}}};
    assert(Solution{}.leftMostColumnWithOne(matrix) == 1);
}