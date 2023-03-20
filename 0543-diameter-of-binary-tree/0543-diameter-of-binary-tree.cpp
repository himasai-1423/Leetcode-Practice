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
    int maxDia = 0;
    int diameter(TreeNode* root, int depth=0) {
        if(!root) return 0;
        
        int left = diameter(root->left);
        int right = diameter(root->right);
        
        maxDia = max(maxDia, left+right);
        
        return max(left, right) +1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root, 0);
        return maxDia;
    }
};