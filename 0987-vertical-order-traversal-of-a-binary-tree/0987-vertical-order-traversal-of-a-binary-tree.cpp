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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;
        int line = 0;
        int level = 0;
        q.push({root, {0, 0}});
        
        while(!q.empty()) {
            pair<TreeNode*, pair<int, int>> p;
            p = q.front();
            TreeNode* node = p.first;
            line = p.second.second;
            level = p.second.first;
            q.pop();
            mp[line][level].insert(node -> val);
            
            if(node -> left != NULL)
                q.push({node -> left, {level + 1, line - 1}});
            if(node -> right != NULL)
                q.push({node -> right, {level + 1, line + 1}});
        }
        
        for(auto it: mp) {
            vector<int> ans;
            for(auto itt: it.second) {
                ans.insert(ans.end(), itt.second.begin(), itt.second.end());
            }
            v.push_back(ans);
        }
        return v;
    }
};