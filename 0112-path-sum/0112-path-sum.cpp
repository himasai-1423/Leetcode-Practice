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
    void checkPathSum(TreeNode* root, int targSum, int currSum, bool &res){
        
        if(!root->left && !root->right){
            if(currSum == targSum) 
                res = true;
            cout<<currSum<<endl;
            return;
        }
        
        if(root->left) checkPathSum(root->left, targSum, currSum + root->left->val, res);
        if(root->right) checkPathSum(root->right, targSum, currSum+root->right->val, res);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        bool res=false;
        int currSum = root->val;
        checkPathSum(root, targetSum, currSum, res);
        return res;
    }
};