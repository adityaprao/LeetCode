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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        queue<pair<TreeNode*, pair<int,int>>> q;
        map<int, map<int,multiset<int>>> mp;
        if (!root) return {{}};
        
        q.push({root, {0,0}});
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int y = q.front().second.second;
                int x = q.front().second.first;
                TreeNode* cur = q.front().first;
                q.pop();
                
                mp[x][y].insert(cur->val);
                if (cur->left) q.push({cur->left, {x-1,y+1}});
                if (cur->right) q.push({cur->right, {x+1,y+1}});
            }
        }
        vector<vector<int>> lvl;
        vector < vector < int >> ans;
        for (auto p: mp) {
            vector < int > col;
            for (auto q: p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
  return ans;        
        
    }
};