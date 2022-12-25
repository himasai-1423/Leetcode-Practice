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
    void traversalHelper(TreeNode* root, int hd, int vd, map<int, map<int, multiset<int>>> &m){
        if(!root) return;
        
        m[hd][vd].insert(root->val);
        
        traversalHelper(root->left, hd-1, vd+1, m);
        traversalHelper(root->right, hd+1, vd+1, m);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        int hd =0, vd=0;
        map<int, map<int, multiset<int>>> m;
        traversalHelper(root, hd, vd, m);
        
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