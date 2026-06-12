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
    void f(TreeNode* root, vector<int>& path, int& ctr){
        if(root == nullptr) return;
        int maxi = INT_MIN;
        for(int num : path){
            maxi = max(maxi, num);
        }
        if(root->val >= maxi) ++ctr;
        path.push_back(root->val);
        f(root->left, path, ctr);
        f(root->right, path, ctr);
        path.pop_back();
    }
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        vector<int> path;
        int ctr = 0 ;
        f(root, path, ctr);
        return ctr;
    }
};
