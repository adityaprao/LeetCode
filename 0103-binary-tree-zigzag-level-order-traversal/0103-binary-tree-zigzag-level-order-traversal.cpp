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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        int ltor = 1;
        vector<vector<int>> ans;
        
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> row(sz);
            for (int i = 0; i < sz; i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                if (ltor)
                    row[i] = cur->val;
                else 
                    row[sz-i-1] = cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);                    
            }
            ans.push_back(row);
            ltor = !ltor;            
        }
        return ans;
    }
};