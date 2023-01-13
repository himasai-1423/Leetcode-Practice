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
    pair<int, int> robTree(TreeNode* root){
        if(!root) return {0, 0};
        
        pair<int, int> left = robTree(root->left);
        pair<int, int> right = robTree(root->right);
        
        int withRoot = root->val + left.second + right.second;
        int withoutRoot = max(left.first, left.second) + max(right.first, right.second);
        
        return {withRoot, withoutRoot};
    }
    
    int rob(TreeNode* root) {
        pair<int, int> res = robTree(root);
        
        return max(res.first, res.second);
    }
};