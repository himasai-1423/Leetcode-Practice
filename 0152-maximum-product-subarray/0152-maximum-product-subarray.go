func maxProduct(nums []int) int {
    mini, maxi, res := 1, 1, math.MinInt32
    
    for _, i := range nums {
        if i==0 {
            mini=1
            maxi=1
            res = max(res, 0)
            continue
        }
        
        temp := maxi*i
        maxi = max(temp, max(mini*i, i))
        mini = min(temp, min(mini*i, i))
        res = max(res, maxi)
    }
    
    return res
}