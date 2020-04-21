/*
            - Construct Binary Search Tree from Preorder Traversal -

Return the root node of a binary search tree that matches the given preorder
traversal.

(Recall that a binary search tree is a binary tree where for every node, any
descendant of node.left has a value < node.val, and any descendant of node.right
has a value > node.val.  Also recall that a preorder traversal displays the
value of the node first, then traverses node.left, then traverses node.right.)

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
                  8
                /   \
               /     \
              5      10
            /   \       \
           /     \       \
          1      7        12

Note:
1 <= preorder.length <= 100
The values of preorder are distinct.
*/

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void deleteTree(TreeNode* root) {
    if(root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void preorderTraversal(TreeNode* root) {
    if(root == nullptr) {
        return;
    }

    cout << root->val << ' ';
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

class Solution {
public:
    TreeNode* bstFromPreorder(const vector<int>& preorder) {
        const int size = preorder.size();
        if(size == 0) {
            return nullptr;
        }

        vector<int> smaller, bigger;
        for(int i = 1; i < size; i++) {
            if(preorder[i] < preorder.front()) {
                smaller.push_back(preorder[i]);
            } else {
                bigger.push_back(preorder[i]);
            }
        }

        TreeNode* curr = new TreeNode(preorder.front());
        curr->left = bstFromPreorder(smaller);
        curr->right = bstFromPreorder(bigger);
        return curr;
    }
};

int main (){

    TreeNode* root = Solution{}.bstFromPreorder({8,5,1,7,10,12});
    preorderTraversal(root);
    deleteTree(root);
}