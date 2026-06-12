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
    bool validBST(TreeNode* root, long long lower_bound, long long upper_bound){
        if(root == nullptr) return true;
        if(root->val >= upper_bound || root->val <= lower_bound) return false;

        bool l = validBST(root->left, lower_bound, root->val);
        bool r = validBST(root->right, root->val, upper_bound);
        return l && r;
    }

    
    bool isValidBST(TreeNode* root) {
        return validBST(root, LLONG_MIN, LLONG_MAX);
    }
};
