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
class Solution
{
public:
    int idx = 0;
    TreeNode *bstFromPreorder(vector<int> &preorder, int parent_value = INT_MAX){
        if(idx==preorder.size() || preorder[idx]>parent_value)
            return NULL;
        int curr_val = preorder[idx];
        TreeNode* node = new TreeNode(curr_val);
        idx++;
        
        node->left = bstFromPreorder(preorder, curr_val);
        node->right = bstFromPreorder(preorder, parent_value);
        
        return node;
    }
};