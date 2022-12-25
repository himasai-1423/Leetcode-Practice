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
    void traverseVertical(TreeNode* root, map<int, map<int, multiset<int>>> &m, int hd, int vd){
        if(!root) return;
        m[hd][vd].insert(root->val);
        traverseVertical(root->left, m, hd-1, vd+1);
        
        traverseVertical(root->right, m, hd+1, vd+1);
        }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> m;
        int hd = 0, vd = 0;
        vector<vector<int>> res;
        
        traverseVertical(root, m, hd, vd);
        
        for(auto i: m){
            vector<int> vec;
            for(auto j: i.second){
                for(auto k: j.second){
                    vec.push_back(k);
                }
            }
            res.push_back(vec);
        }
            
            
        return res;
    }
};