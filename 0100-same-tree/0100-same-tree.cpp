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
    bool res = true;
    bool check(TreeNode* p, TreeNode *q) {
        if(!p && !q) return true;
        
        if(!p || !q) return false;
        
        if(p->val!= q->val) return false;
        
        return check(p->right, q->right) && check(p->left, q->left);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        
        return check(p, q);
    }
};