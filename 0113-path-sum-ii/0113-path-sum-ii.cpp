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
    vector<int> vec;
    void checkPath(TreeNode* root, int targetSum, vector<vector<int>> &res){
        if(!root) return;
        
        vec.push_back(root->val);
        
        if(!root->left && !root->right && targetSum==root->val){
            res.push_back(vec);
        }
        
        checkPath(root->left, targetSum-root->val, res);
        checkPath(root->right, targetSum-root->val, res);
        
        vec.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;        
        checkPath(root, targetSum, res);
        return res;
    }
};