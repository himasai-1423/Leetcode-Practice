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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);

        return treeBalancer(arr, 0, arr.size()-1);
    }
    
    TreeNode* treeBalancer(vector<int> &arr, int l, int r){
        if(l>r) return NULL;
        
        int mid = l + (r-l)/2;
        
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = treeBalancer(arr, l, mid-1);
        node->right = treeBalancer(arr, mid+1, r);
        
        return node;
    }
    
    void inorder(TreeNode* root, vector<int> &arr){
        if(!root) return;
        
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
};