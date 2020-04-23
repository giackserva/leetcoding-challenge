/*
                        - Bitwise AND of Numbers Range -

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of
all numbers in this range, inclusive.

Example 1:
Input: [5,7]
Output: 4

Example 2:
Input: [0,1]
Output: 0
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int answer = m;
        while(answer != 0 && m < n) {
            answer &= ++m;
        }
        return answer;
    }
};

int main() {
    assert(Solution{}.rangeBitwiseAnd(5,7) == 4);
    assert(Solution{}.rangeBitwiseAnd(0,1) == 0);
}