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
    int cameraCount(TreeNode* root, int &camera){
        if(!root) return 1;
        
        int left = cameraCount(root->left, camera);
        int right = cameraCount(root->right, camera);
        
        if(left==-1 || right==-1){
            camera++;
            return 0;
        }
        
        else if(left == 0 || right == 0)
            return 1;
        
        return -1;        
    }
    int minCameraCover(TreeNode* root) {
        int camera = 0;
        if(cameraCount(root, camera)==-1) camera++;
        
        return camera;
    }
};