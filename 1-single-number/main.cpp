/*
Given a non-empty array of integers, every element appears twice except for one.
Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it
without using extra memory?

Example 1:
Input: [2,2,1]
Output: 1

Example 2:
Input: [4,1,2,1,2]
Output: 4
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(const vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor{});
    }
};

int main (){
    assert(Solution{}.singleNumber({2,2,1}) == 1);
    assert(Solution{}.singleNumber({4,1,2,1,2}) == 4);
}