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
    TreeNode* findLCA(TreeNode* root, int p, int q){
        if(!root) return NULL;
        if(root->val == p || root->val == q) return root;
        
        TreeNode* left= findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);
        
        if(left && right) return root;
        
        return (left==NULL)?right:left;
        
    }
    
    bool traverse(TreeNode* root, int val, string &path){
        if(!root) return false;
        if(root->val == val) return true;
        
        path.push_back('L');
        if(traverse(root->left, val, path)) return true;
        path.pop_back();
        
        path.push_back('R');
        if(traverse(root->right, val, path)) return true;
        path.pop_back();
        
        return false;
    }
    
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);
        
        string LCA_to_start="", LCA_to_dest="";
        
        traverse(lca, startValue, LCA_to_start);
        traverse(lca, destValue, LCA_to_dest);
        
        for(auto& c : LCA_to_start) c = 'U';

        return LCA_to_start + LCA_to_dest;
    }
};