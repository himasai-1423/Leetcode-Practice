/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* res = NULL;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        if(root->val>p->val && root->val>q->val)
            lowestCommonAncestor(root->left, p, q);
        
        else if(root->val<p->val && root->val<q->val)
            lowestCommonAncestor(root->right, p, q);
        
        else
            res = root;
        
        return res;
    }
};