/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* inorder(TreeNode* root, int k, int& ctr){
        if(root == nullptr) return root;

        TreeNode* left = inorder(root->left, k, ctr);
        if(left) return left;

        ++ctr;
        if(ctr == k) return root;

        return inorder(root->right, k, ctr);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ctr = 0 ;
        TreeNode* ans = inorder(root, k, ctr);
        if(ans == nullptr) return -1;
        return ans->val;
    }
};
