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
    void pathTraversal(TreeNode* root, vector<string> &str, string s){
        if(!root->left && !root->right){
            str.push_back(s);
            return;
        }
        
        if(root->left) 
            pathTraversal(root->left, str, s+"->"+to_string(root->left->val));
        if(root->right) 
            pathTraversal(root->right, str, s+"->"+to_string(root->right->val));
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> str;

        pathTraversal(root, str, to_string(root->val));
        return str;
    }
};