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
    
    int findDiameter(TreeNode* root, int &ans){
        if(root == nullptr) return 0;
        int lh = findDiameter(root->left, ans);
        int rh = findDiameter(root->right, ans);

        ans = max(ans, lh  + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        int ans = 0 ;
        findDiameter(root, ans);
        return ans;
    }
};
