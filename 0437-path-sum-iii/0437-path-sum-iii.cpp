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
    int ans=0;
    int pathSum(TreeNode* root, long targetSum) {
        if(root){
            dfs(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
    
    void dfs(TreeNode* root, long targetSum){
        if(!root) return;
        
        if(root->val == targetSum) ans++;
        
        dfs(root->left, targetSum-root->val);
        dfs(root->right, targetSum - root->val);
    }
};