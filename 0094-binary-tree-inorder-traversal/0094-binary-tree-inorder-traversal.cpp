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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        
        while(root||!st.empty()){
            if(root){
                st.push(root);
                root = root->left;
            }
            
            else{
                TreeNode* node = st.top();
                st.pop();
                res.push_back(node->val);
                
                if(node->right)
                    root = node->right;
            }
        }
        return res;
    }
};