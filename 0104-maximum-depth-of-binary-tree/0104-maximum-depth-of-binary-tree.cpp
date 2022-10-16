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
    int depth(TreeNode* root, int &d){
        if(!root) return 0;
        
        int lDepth = depth(root->left, d);
        int rDepth = depth(root->right, d);
        
        int temp = max(lDepth, rDepth);
        d = max(d, temp);
        
        return temp+1;
    }
    int maxDepth(TreeNode* root) {
        int d = 0;
        int res = depth(root, d);
        return res;
    }
};