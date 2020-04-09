/*
                        - Backspace String Compare -

Given two strings S and T, return if they are equal when both are typed into
empty text editors. # means a backspace character.

Example 1:
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:
Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:
Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:
Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

Note:
1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.

Follow up:
Can you solve it in O(N) time and O(1) space?
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool backspaceCompare(const string& S, const string& T) {
        stack<char> s, t;
        for(char c : S) {
            if(c != '#') {
                s.push(c);
            }
            else if (!s.empty()) {
                s.pop();
            }
        }

        for(char c : T) {
            if(c != '#') {
                t.push(c);
            }
            else if (!t.empty()) {
                t.pop();
            }
        }

        if(s.size() != t.size()) {
            return false;
        }

        while(!s.empty()) {
            if(s.top() != t.top()) {
                return false;
            }
            s.pop();
            t.pop();
        }

        return true;
    }
};

int main (){
    assert(Solution{}.backspaceCompare("ab#c", "ad#c"));
    assert(Solution{}.backspaceCompare("ab##", "c#d#"));
    assert(Solution{}.backspaceCompare("a##c", "#a#c"));
    assert(!Solution{}.backspaceCompare("a#c", "b"));
}