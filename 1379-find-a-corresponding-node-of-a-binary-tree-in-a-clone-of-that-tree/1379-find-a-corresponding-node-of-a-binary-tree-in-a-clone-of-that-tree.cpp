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
    void findTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode* &res) {
        if(!original) return; 
        
        findTargetCopy(original->left, cloned->left, target, res);
        if(original==target){
            res = cloned;
            return;
        }
        findTargetCopy(original->right, cloned->right, target, res);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* res= NULL;
        findTargetCopy(original, cloned, target, res);
        return res;
    }
};