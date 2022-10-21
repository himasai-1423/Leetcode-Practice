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
    int checkHeight(TreeNode* root, bool &res){
        if(!root) return 0;
        int lHeight = checkHeight(root->left, res);
        int rHeight = checkHeight(root->right, res);
        
        if(abs(lHeight-rHeight)>1){
            res = false;
            cout<<res<<endl;
        } 
        
        return max(lHeight, rHeight) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        bool res = true;
        checkHeight(root, res);
        return res;
    }
};