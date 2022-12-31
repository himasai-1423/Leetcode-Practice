/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int longestZigZag(TreeNode root) {
        Pair p=longestZigZag_(root);
        return p.maxLen;
    }
    
    public Pair longestZigZag_(TreeNode root){
        if(root==null){
            return new Pair();
        }
        
        Pair left=longestZigZag_(root.left);
        Pair right=longestZigZag_(root.right);
        
        Pair ans=new Pair();
        
        ans.maxLen=Math.max(left.maxLen,Math.max(right.maxLen,Math.max(left.backwardSlope,right.forwardSlope)+1));
        ans.forwardSlope=left.backwardSlope+1;
        ans.backwardSlope=right.forwardSlope+1;
        
        return ans;
    }
}

class Pair{
    int forwardSlope=-1;
    int backwardSlope=-1;
    int maxLen=0;
}
