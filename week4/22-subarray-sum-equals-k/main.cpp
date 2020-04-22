/*
                        - Subarray Sum Equals K -

Given an array of integers and an integer k, you need to find the total number
of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2

Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer
k is [-1e7, 1e7].
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(const vector<int>& nums, int k) {
        int cumulativeSum = 0;
        unordered_multiset<int> sums;
        sums.emplace(0);

        int answer = 0;
        for(int i : nums) {
            cumulativeSum += i;
            answer += sums.count(cumulativeSum - k);

            sums.insert(cumulativeSum);
        }

        return answer;
    }
};

int main() {
    assert(Solution{}.subarraySum({1,1,1}, 2) == 2);
}