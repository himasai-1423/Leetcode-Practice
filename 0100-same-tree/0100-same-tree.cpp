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
    void compareTree(TreeNode* p, TreeNode* q, bool &res){
        if(!p && !q) return;
        
        if(!p || !q){
            res = false;
            return;
        }
        
        if(p->val != q->val) res = false;
        
        compareTree(p->left, q->left, res);
        compareTree(p->right, q->right, res);
        
        return;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool res=true;
        compareTree(p, q, res);
        return res;
    }
};