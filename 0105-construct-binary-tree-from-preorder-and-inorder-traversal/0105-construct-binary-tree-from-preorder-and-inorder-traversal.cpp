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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIndex = 0;
        return treeBuilder(preorder, inorder, rootIndex, 0, inorder.size()-1);
    }
    
    TreeNode* treeBuilder(vector<int>& preorder, vector<int>& inorder, int &rootIndex, int l, int r) {
        if(l>r) return NULL;
        int pivot = l;
        
        while(inorder[pivot] != preorder[rootIndex]) pivot++;
        
        TreeNode* node = new TreeNode(inorder[pivot]);
        rootIndex++;
        
        node->left = treeBuilder(preorder, inorder, rootIndex, l , pivot-1);
        node->right = treeBuilder(preorder, inorder, rootIndex, pivot+1, r);

        return node;
    }
};