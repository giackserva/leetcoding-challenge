/*
                            - Contiguous Array -

Given a binary array, find the maximum length of a contiguous subarray with
equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0
and 1.

Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxLength(const vector<int>& nums) {
        const int size = nums.size();
        int answer = 0;
        int count = 0;
        unordered_map<int, int> count_map;
        count_map[0] = -1;

        for(int i = 0; i < size; i++) {
            if(nums[i] == 0) count -= 1;
            else count += 1;

            auto it = count_map.find(count);
            if(it != count_map.end()) {
                answer = max(answer, i - it->second);
            } else {
                count_map[count] = i;
            }
        }

        return answer;
    }
};

int main (){
    assert(Solution{}.findMaxLength({0, 1}) == 2);
    assert(Solution{}.findMaxLength({0, 1, 0}) == 2);
    assert(Solution{}.findMaxLength({0, 0, 1, 0, 0, 0, 1, 1}) == 6);
}