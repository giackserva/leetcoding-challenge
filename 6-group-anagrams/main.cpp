/*
                            - Group Anagrams -

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> count(const string& s) {
        vector<int> letters(26, 0);
        for(char c : s) {
            letters[c - 'a']++;
        }
        return letters;
    }
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        map<vector<int>, vector<string>> groups;

        for(auto& s : strs) {
            vector<int> letters = count(s);
            groups[letters].push_back(s);
        }

        vector<vector<string>> ret;
        for(auto& pair : groups) {
            ret.push_back(pair.second);
        }
        return ret;
    }
};

int main (){
    const vector<string> strings {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groups = Solution{}.groupAnagrams(strings);
    for(auto& group : groups) {
        for(auto& string : group) {
            cout << string << ' ';
        }
        cout << '\n';
    }
}