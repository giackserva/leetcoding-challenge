/*
                            - Move Zeroes -

Given an array nums, write a function to move all 0's to the end of it while
maintaining the relative order of the non-zero elements.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int size = nums.size();
        int index = 0;
        auto equalToZero = [](int i){ return i == 0; };

        while(true) {
            auto itZero = find_if(nums.begin() + index, nums.end(), equalToZero);
            int zero = distance(nums.begin(), itZero);
            if(zero == size) break;

            auto itNonZero = find_if_not(nums.begin() + zero, nums.end(), equalToZero);
            int nonZero = distance(nums.begin(), itNonZero);
            if(nonZero == size) break;

            swap(nums[zero], nums[nonZero]);
            index = zero + 1;
        }
    }
};

int main (){
    vector<int> nums {0,1,0,3,12};
    const vector<int> sol {1,3,12,0,0};
    Solution{}.moveZeroes(nums);
    assert(equal(nums.begin(), nums.end(), sol.begin()));
}