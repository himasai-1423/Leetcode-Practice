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
    TreeNode* node = NULL;
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        
        if(root->val == val){
            node = root;
            return node;
        } 
        
        if(root->val>val)
            searchBST(root->left, val);
        
        else
            searchBST(root->right, val);
        
        return node;
    }
};