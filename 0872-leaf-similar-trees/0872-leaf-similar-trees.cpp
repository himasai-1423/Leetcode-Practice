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
    void checkTree1(TreeNode* root1, vector<int> &v1){
        if(root1->left) 
            checkTree1(root1->left, v1);
        
        if(!root1->left && !root1->right){
            v1.push_back(root1->val);
            return;
        }
        
        if(root1->right)
            checkTree1(root1->right, v1);
    }
    void checkTree2(TreeNode* root2, vector<int> &v2){
        if(root2->left) 
            checkTree2(root2->left, v2);
        
        if(!root2->left && !root2->right){
            v2.push_back(root2->val);
            return;
        }
        
        if(root2->right)
            checkTree2(root2->right, v2);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        
        checkTree1(root1, v1);
        checkTree2(root2, v2);
        
        if(v1==v2)
            return true;
        
        return false;
    }
};