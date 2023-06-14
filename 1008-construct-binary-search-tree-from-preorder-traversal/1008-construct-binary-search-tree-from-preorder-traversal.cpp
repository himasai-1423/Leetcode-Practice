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
private:
    int idx = 0;
    TreeNode* treeBuilder(vector<int>& preorder, int parVal) {
        if(idx>=preorder.size() || preorder[idx]>parVal) 
            return NULL;
        
        TreeNode *node = new TreeNode(preorder[idx]);
        idx++;
        node->left = treeBuilder(preorder, node->val);
        node->right = treeBuilder(preorder, parVal);
        
        return node;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return treeBuilder(preorder, INT_MAX);
    }
};