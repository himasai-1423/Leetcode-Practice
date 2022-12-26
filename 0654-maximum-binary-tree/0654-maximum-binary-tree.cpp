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
    TreeNode* buildBinaryTree(vector<int> &nums, int l, int r){
        if(l==r) return NULL;
        
        int maxi = findMax(nums, l, r);
        
        TreeNode* node = new TreeNode(nums[maxi]);
        node->left = buildBinaryTree(nums, l, maxi);
        node->right = buildBinaryTree(nums, maxi+1, r);
        
        return node;
    }
    
    int findMax(vector<int> &nums, int l, int r){
        int maxi=l;
        for(int i=l; i<r; i++)
            if(nums[i]>nums[maxi])
                maxi=i;
        
        return maxi;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildBinaryTree(nums, 0, nums.size());
    }
};