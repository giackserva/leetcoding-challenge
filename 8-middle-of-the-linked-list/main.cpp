/*
Middle of the Linked List

Given a non-empty, singly linked list with head node head, return a middle node
of linked list.

If there are two middle nodes, return the second middle node.

Example 1:
Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is
[3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and
ans.next.next.next = NULL.

Example 2:
Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.

Note:
The number of nodes in the given list will be between 1 and 100.
*/

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* buildList(const vector<int>& nums) {
    ListNode dummy{-1};
    ListNode* curr = &dummy;

    for(int n : nums) {
        curr->next = new ListNode{n};
        curr = curr->next;
    }

    return dummy.next;
}

void deleteList(ListNode* head) {
    while(head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        bool advanceMiddle = false;
        ListNode* middle = head;
        while(head != nullptr) {
            if(advanceMiddle) {
                middle = middle->next;
            }
            advanceMiddle = !advanceMiddle;
            head = head->next;
        }
        return middle;
    }
};

int main (){
    ListNode* head = buildList({1, 2, 3, 4, 5});
    assert(Solution{}.middleNode(head) == head->next->next);
    deleteList(head);
    head = buildList({1, 2, 3, 4, 5, 6});
    assert(Solution{}.middleNode(head) == head->next->next->next);
    deleteList(head);
}