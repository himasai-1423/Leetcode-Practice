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
        int rootNode = postorder.size()-1;
        return treeBuilder(inorder, postorder, rootNode, 0, rootNode);
    }
    
    TreeNode* treeBuilder(vector<int>& inorder, vector<int>& postorder, int &rootIndex, int l, int r) {
        if(l>r) return NULL;
        
        int pivot = l;
        while(postorder[rootIndex] != inorder[pivot]) pivot++;
        
        TreeNode* node = new TreeNode(inorder[pivot]);
        rootIndex--;
        
        node->right = treeBuilder(inorder, postorder, rootIndex, pivot+1, r);
        node->left = treeBuilder(inorder, postorder, rootIndex, l, pivot-1);
        
        return node;
    }
};