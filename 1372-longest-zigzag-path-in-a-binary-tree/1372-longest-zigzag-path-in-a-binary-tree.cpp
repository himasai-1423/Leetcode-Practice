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
    class Pair {
    public:
        int forwardSlash = -1;
        int backwardSlash = -1;
        int maxZZ = 0;
    };
    
    Pair findZigZag(TreeNode* root){
        if(!root) {
            Pair nodeAns;
            return nodeAns;
        }
        
        Pair left = findZigZag(root->left);
        Pair right = findZigZag(root->right);
        
        Pair nodeAns;
        
        nodeAns.maxZZ = max(max(left.maxZZ, right.maxZZ) ,max(left.backwardSlash, right.forwardSlash)+1);
        nodeAns.forwardSlash = left.backwardSlash +1;
        nodeAns.backwardSlash = right.forwardSlash +1;
        
        return nodeAns;
    }
    
    
    int longestZigZag(TreeNode* root) {
        Pair maxi = findZigZag(root);
        
        return maxi.maxZZ;
    }
};