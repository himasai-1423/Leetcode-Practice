func removeDuplicates(nums []int) int {
    i, j, res := 0, 1, 1
    
    for j<len(nums) {
        if nums[i] != nums[j] {
            res++
            i += 1
            nums[i] = nums[j]
        }
        j++
    }
    return res
}