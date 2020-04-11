/*
                        - Diameter of Binary Tree -

Given a binary tree, you need to compute the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two
nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges
between them.
*/

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        : val(x) , left(nullptr) , right(nullptr) { }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x) , left(left) , right(right) { }
};

void deleteTree(TreeNode* root) {
    if(root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

class Solution {
    int visit(TreeNode* root, int& maxPath) {
        if(root == nullptr) {
            return 0;
        }

        const int depthRight = visit(root->right, maxPath);
        const int depthLeft = visit(root->left, maxPath);

        maxPath = max(maxPath, depthRight + depthLeft);

        return 1 + max(depthRight, depthLeft);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxPath{0};
        visit(root, maxPath);
        return maxPath;
    }
};

int main (){
    TreeNode* root = new TreeNode{1,
                                  new TreeNode{2,
                                               new TreeNode{4},
                                               new TreeNode{5}},
                                  new TreeNode {3}};

    assert(Solution{}.diameterOfBinaryTree(root) == 3);

    deleteTree(root);

    root = new TreeNode{1,
                        new TreeNode{2,
                                     new TreeNode{4},
                                     new TreeNode{5, new TreeNode{6}, nullptr}},
                        new TreeNode {3}};

    assert(Solution{}.diameterOfBinaryTree(root) == 4);

    deleteTree(root);
}