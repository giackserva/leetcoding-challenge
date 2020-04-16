/*
                        - Valid Parenthesis String -

Given a string containing only three types of characters: '(', ')' and '*',
write a function to check whether this string is valid. We define the validity
of a string by these rules:

- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left
  parenthesis '(' or an empty string.

An empty string is also valid.

Example 1:
Input: "()"
Output: True

Example 2:
Input: "(*)"
Output: True

Example 3:
Input: "(*))"
Output: True

Note:
The string size will be in the range [1, 100].
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
    bool backtrack(string& s, int index, int opened) {
        if(opened < 0 || index == (int) s.size()) {
            return opened == 0;
        }

        const char curr = s[index];
        if(curr == '(') {
            opened++;
            return backtrack(s, index + 1, opened);
        } else if (curr == ')') {
            if(opened == 0) {
                return false;
            }
            opened--;
            return backtrack(s, index + 1, opened);
        }

        return backtrack(s, index + 1, opened) // consider it empty
                || backtrack(s, index + 1, opened - 1) // consider it closed
                || backtrack(s, index + 1, opened + 1); // consider it opened
    }
public:
    bool checkValidString(string s) {
        return backtrack(s, 0, 0);
    }
};

int main (){
    assert(Solution{}.checkValidString("()"));
    assert(Solution{}.checkValidString("(*)"));
    assert(Solution{}.checkValidString("(*))"));
}