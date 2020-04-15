/*
                       - Product of Array Except Self -

Given an array nums of n integers where n > 1,  return an array output such that
output[i] is equal to the product of all the elements of nums except nums[i].

Example:
Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or
suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not
count as extra space for the purpose of space complexity analysis.)
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int size = nums.size();
        vector<int> answer (size);
        answer[0] = nums[0];

        int firstZeroIndex = -1;
        for(int i = 1; i < size; i++) {
            if(i == 0) {
                if(firstZeroIndex == -1) {
                    firstZeroIndex = i;
                    answer[i] = answer[i-1];
                } else {
                    answer.assign(size, 0);
                    return answer;
                }
            }
            else {
                answer[i] = nums[i] * answer[i-1];
            }
        }

        if(firstZeroIndex != -1) {
            answer.assign(size, 0);
            answer[firstZeroIndex] = nums[size - 1];
            return answer;
        }

        int product = 1;
        for(int i = size - 1; i > 0; i--) {
            answer[i] = product * answer[i - 1];
            product *= nums[i];
        }
        answer[0] = product;

        return answer;
    }
};

int main (){
    vector<int> nums{1,2,3,4};
    vector<int> answer{24,12,8,6};

    vector<int> output = Solution{}.productExceptSelf(nums);
    assert(equal(answer.begin(), answer.end(), output.begin()));

    nums = vector<int>{1,0,2,3,4};
    answer = vector<int>{0,24,0,0,0};

    output = Solution{}.productExceptSelf(nums);
    assert(equal(answer.begin(), answer.end(), output.begin()));

    nums = vector<int>{1,0,2,3,4,0};
    answer = vector<int>{0,0,0,0,0,0};

    output = Solution{}.productExceptSelf(nums);
    assert(equal(answer.begin(), answer.end(), output.begin()));
}