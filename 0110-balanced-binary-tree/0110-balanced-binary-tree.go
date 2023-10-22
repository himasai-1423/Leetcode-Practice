/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(root *TreeNode) bool {
    if root == nil {
        return true
    }
      
    _, res:= dfs(root)   
    return res
}

func dfs(root *TreeNode) (int, bool) {
    if root == nil {
        return 0, true
    }
    
    left, leftBool := dfs(root.Left)
    right, rightBool := dfs(root.Right)
    
    height := max(left, right)
    if abs(left-right)>1 {
        return height, false
    }
    res := leftBool && rightBool 
    
    return height+1, res
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}