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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIndex=postorder.size()-1;
        return builder(inorder, postorder, 0, inorder.size()-1, rootIndex);
    }
    
    TreeNode* builder(vector<int>& inorder, vector<int>& postorder, int left, int right, int &rootIndex){
        if(left>right)
            return NULL;
        
        int pivot = left;
        while(inorder[pivot] != postorder[rootIndex]) pivot++;
        
        rootIndex--;
        
        TreeNode* node = new TreeNode(inorder[pivot]);
        
        node->right = builder(inorder, postorder, pivot+1, right, rootIndex);
        node->left = builder(inorder, postorder, left, pivot-1, rootIndex);
        
        return node;
    }
};