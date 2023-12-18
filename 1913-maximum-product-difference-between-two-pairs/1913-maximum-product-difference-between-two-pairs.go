func maxProductDifference(nums []int) int {
    n := len(nums)
    
    sort.Ints(nums)
    
    maxi := nums[n-1]*nums[n-2]
    mini := nums[0] *nums[1]
    
    return maxi - mini
}