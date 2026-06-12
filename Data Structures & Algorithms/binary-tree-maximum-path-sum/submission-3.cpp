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
    int findSum(TreeNode* root, int& maxi){
        if(root == nullptr) return 0;
        int lSum = max(0, findSum(root->left, maxi));
        int rSum = max(0, findSum(root->right, maxi));

        maxi = max(maxi, lSum + rSum + root->val);
        return root->val + max(lSum, rSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = root->val;
        findSum(root, maxi);
        return maxi;
    }
};
