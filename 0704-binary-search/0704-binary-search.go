func search(nums []int, target int) int {
    hi := len(nums)-1
    lo := 0
    for lo<=hi {
        mid := lo + (hi-lo)/2
        if nums[mid] == target {
            return mid
        } else if nums[mid] > target {
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    return -1
}