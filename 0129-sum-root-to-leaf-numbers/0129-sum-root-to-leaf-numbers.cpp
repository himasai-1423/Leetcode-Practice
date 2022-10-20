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
    void calculateNumbers(TreeNode* root, vector<int> &val, int num){
        if(!root->left && !root->right){
            cout<<"Val: "<<num<<endl;
            val.push_back(num);
            return;
        }
        
        if(root->left) calculateNumbers(root->left, val, num*10+root->left->val);
        if(root->right) calculateNumbers(root->right, val, num*10+root->right->val);
    }
    
    int sumNumbers(TreeNode* root) {
        vector<int> val;
        calculateNumbers(root, val, root->val);
        
        int res;
        for(int i=0; i<val.size(); i++){
            res+=val[i];
        }
        return res;
    }
};