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
    int findDepth(TreeNode* root){
        if(root == NULL) return 0;
        int lh = findDepth(root->left);
        int rh = findDepth(root->right);
        return 1 + max(lh, rh);
    }
    void findDiameter(TreeNode* root, int &ans){
        if(root == NULL) return ;

        int lh = findDepth(root->left);
        int rh = findDepth(root->right);

        ans = max(ans, lh + rh);
        findDiameter(root->left, ans);
        findDiameter(root->right, ans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        int ans = 0 ;
        findDiameter(root, ans);
        return ans;
    }
};
