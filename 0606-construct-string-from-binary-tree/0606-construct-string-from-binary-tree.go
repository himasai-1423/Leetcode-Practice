/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func tree2str(root *TreeNode) string {
    str := strconv.Itoa(root.Val)
    if root.Left != nil {
        str += "(" + tree2str(root.Left) + ")"
    }
    
    if root.Right != nil {
        if root.Left == nil {
            str += "()";
        }
        str += "(" + tree2str(root.Right) + ")"
    }
    return str
}