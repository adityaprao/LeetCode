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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        ino(root, ans);
        return ans;        
    }
    
    void ino(TreeNode* root, vector<int> &ans)
    {
        if (!root) return;
        ino(root->left, ans);
        ans.push_back(root->val);
        ino(root->right, ans);       
        
    }
};