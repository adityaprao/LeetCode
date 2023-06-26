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
    
    int ht(TreeNode* node)
    {
        if (node == NULL) return 0;
        int lht = ht(node->left);
        int rht = ht(node->right);
        
        if (lht==-1 or rht==-1) return -1;
        
        if (abs(lht - rht) > 1) return -1;
        return 1 + max(lht, rht);
    }
    
    
    bool isBalanced(TreeNode* root) {
        if (ht(root) == -1) return false;
        return true;
        
    }
};