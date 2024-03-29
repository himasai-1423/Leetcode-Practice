/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> res;
    
    void preTraversal(Node* root) {
        if(!root) return;
        
        res.push_back(root->val);
        for(auto child: root->children) 
            preTraversal(child);
    }
    
    vector<int> preorder(Node* root) {
        preTraversal(root);
        
        return res;
    }
};