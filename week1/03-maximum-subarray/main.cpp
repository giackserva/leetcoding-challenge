/*
                        - Maximum Subarray -

Given an integer array nums, find the contiguous subarray (containing at least
one number) which has the largest sum and return its sum.

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6

Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:
If you have figured out the O(n) solution, try coding another solution using the
divide and conquer approach, which is more subtle.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        int sol = numeric_limits<int>::min();

        int curr = 0;
        for(int n : nums) {
            curr += n;
            sol = max(sol, curr);

            if(curr < 0) {
                curr = 0;
            }
        }

        return sol;
    }
};

int main (){
    assert(Solution{}.maxSubArray({-2,1,-3,4,-1,2,1,-5,4}) == 6);
}