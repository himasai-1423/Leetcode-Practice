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
    int maxSum(TreeNode* root, int &res){
        if(!root) return 0;
        
        int lsum = maxSum(root->left, res);
        int rsum = maxSum(root->right, res);
        
        int maxi= max(max(lsum, rsum)+root->val, root->val);
        int temp = max(maxi, lsum+rsum+root->val);
        res = max(res, temp);
        
        return maxi;
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        maxSum(root, res);
        return res;
    }
};