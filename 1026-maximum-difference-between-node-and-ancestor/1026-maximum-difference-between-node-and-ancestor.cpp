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
    int diff=INT_MIN;
    
    void checkAncestor(TreeNode* root, int mini, int maxi){
        if(!root)
            return;
        
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        
        diff = max(diff, maxi-mini);
        
        checkAncestor(root->left, mini, maxi);
        checkAncestor(root->right, mini, maxi);
        
        return;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        checkAncestor(root, INT_MAX, INT_MIN);
        return diff;
    }
};