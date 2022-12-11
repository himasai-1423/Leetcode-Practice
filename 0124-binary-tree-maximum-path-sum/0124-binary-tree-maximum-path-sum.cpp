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
    int res = INT_MIN;
    int checkSum(TreeNode* root){
        if(!root)
            return 0;
        
        int left = checkSum(root->left);
        int right = checkSum(root->right);
        
        int maxi = max(max(left, right)+root->val, root->val) ;
        int temp = max(maxi, left+right+root->val);
        res = max(temp, res);
        
        return maxi;
    }
    
    int maxPathSum(TreeNode* root) {
        checkSum(root);
        return res;
    }
};