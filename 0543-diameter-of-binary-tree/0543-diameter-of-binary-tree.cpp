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
    
    int calc(TreeNode* node, int &maxD)
    {
        if (!node) return 0;
        int lht = calc(node->left, maxD);
        int rht = calc(node->right, maxD);
        
        maxD = max(maxD, lht+rht);
        
        return 1 + max(lht, rht);        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diam = 0;
        int ht = calc(root, diam);
        return diam;
    }
};