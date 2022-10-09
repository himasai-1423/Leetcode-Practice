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
    int diameter(TreeNode* root, int &res){
        if(root==NULL) return 0;
        
        int left_dia = diameter(root->left, res);
        int right_dia = diameter(root->right, res);

        res = max(res, left_dia+right_dia);
        return max(left_dia, right_dia) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        diameter(root, res);
        return res;
    }
};