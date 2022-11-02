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
    int findBottomLeftValue(TreeNode* root) {
        int res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(root && !q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* ptr = q.front();
                q.pop();
                
                if(i==0) res= ptr->val;
                
                if(ptr->left) q.push(ptr->left);
                if(ptr->right) q.push(ptr->right);
            }
        }
        return res;
    }
};