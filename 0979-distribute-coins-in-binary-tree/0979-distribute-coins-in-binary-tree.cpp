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
    int distributeCoins(TreeNode* root) {
        int maxMoves = 0;
        calculateMoves(root, maxMoves);
        
        return maxMoves;
    }
    
    int calculateMoves(TreeNode* root, int &maxMoves){
        if(!root) return 0;
        
        int left = calculateMoves(root->left, maxMoves);
        int right = calculateMoves(root->right, maxMoves);
        
        maxMoves += abs(left) + abs(right);
        
        return root->val+left+right-1;
    }
};