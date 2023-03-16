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
        int rootIdx = postorder.size()-1;
        return treeBuilder(inorder, postorder, 0, inorder.size()-1, rootIdx);
    }
    
    TreeNode* treeBuilder(vector<int>& inorder, vector<int>& postorder, int left, 
                          int right, int &rootIdx) {
        if(left>right)
            return NULL;
        
        int pivot = left;
        
        while(inorder[pivot] != postorder[rootIdx]) pivot++;
        
        TreeNode* node = new TreeNode(postorder[rootIdx]);
        rootIdx--;
        
        node->right = treeBuilder(inorder, postorder, pivot+1, right, rootIdx);
        node->left = treeBuilder(inorder, postorder, left, pivot-1, rootIdx);
        
        
        return node;
    }
};