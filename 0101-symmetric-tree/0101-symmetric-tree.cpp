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
    bool checkTree(TreeNode* left1, TreeNode* right1) {
        if(!left1 && !right1) return true;
        if(!left1 || !right1) return false;
        
        if(left1->val != right1->val) return false;
        
        return checkTree(left1->right, right1->left) 
            && checkTree(left1->left, right1->right);
    }
    
    bool isSymmetric(TreeNode* root) { 
        return checkTree(root->left, root->right);
    }
};