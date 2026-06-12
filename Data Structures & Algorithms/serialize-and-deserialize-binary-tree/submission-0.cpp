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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node == nullptr) s += "#,";
            else {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0 || data == "#,") return nullptr;

        queue<TreeNode*> q;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#") node->left = nullptr;
            else {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            getline(s, str, ',');
            if(str == "#") node->right = nullptr;
            else {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};
