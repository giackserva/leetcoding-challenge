/*
                    - Search in Rotated Sorted Array -

Suppose an array sorted in ascending order is rotated at some pivot unknown to
you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index,
otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

#include<bits/stdc++.h>

using namespace std;

    class Solution {
    public:
        int search(const vector<int>& nums, int target) {
            if(nums.empty()) {
                return -1;
            }
            const int size = nums.size();
            if(size == 1) {
                return nums[0] == target ? 0 : -1;
            }

            int b = 0;
            int e = size - 1;

            // only if rotation happened
            if(nums[b] > nums[e]) {
                // look for pivot (a number smaller than the element to its left)
                while(b <= e) {
                    const int curr = b + (e - b) / 2;
                    if(curr - 1 >= 0 && nums[curr] < nums[curr - 1]) {
                        b = curr;
                        break;
                    }

                    if(nums[curr] >= nums[0]) {
                        b = curr + 1;
                    } else {
                        e = curr - 1;
                    }
                }

                if(target >= nums.front()) {
                    e = b - 1;
                    b = 0;
                } else {
                    e = size - 1;
                }
            }

            auto it = lower_bound(nums.begin() + b, nums.begin() + e + 1, target);
            if (it != nums.begin() + e + 1 && target == *it) {
                return distance(nums.begin(), it);
            }
            return -1;
        }
    };

int main (){
    assert(Solution{}.search({4,5,6,7,0,1,2}, 0) == 4);
    assert(Solution{}.search({4,5,6,7,0,1,2}, 3) == -1);
}