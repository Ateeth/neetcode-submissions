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
    int f(TreeNode* root, int maxi){
        if(root == nullptr) return 0;
        int ans = 0 ;
        if(root->val >= maxi){
            ans = 1;
        }

        maxi = max(root->val, maxi);
        ans += f(root->left, maxi);
        ans += f(root->right, maxi);

        return ans;
    }
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int ctr = f(root, root->val);
        return ctr;
    }
};
