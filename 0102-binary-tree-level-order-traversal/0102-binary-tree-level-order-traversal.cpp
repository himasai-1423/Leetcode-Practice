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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            vector<int> v;
            for(int i=0; i<n ; i++){
                TreeNode* ele = q.front();
                
                if(ele->left) q.push(ele->left);
                if(ele->right) q.push(ele->right);
                q.pop();
                
                v.push_back(ele->val);
            }
            res.push_back(v);
        }
        return res;
    }
};