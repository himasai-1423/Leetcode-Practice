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
    void addLeft(TreeNode* root, int &sum){
        if(!root->left && !root->right) return;
        
        if(root->left && (!root->left->left && !root->left->right)) 
            sum += root->left->val ;
        
        else if(root->left) addLeft(root->left, sum);
        if(root->right) addLeft(root->right, sum);
        
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        addLeft(root, sum);
        
        return sum;
    }
};