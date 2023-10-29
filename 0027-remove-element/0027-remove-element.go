func removeElement(nums []int, val int) int {
    cnt := 0
    marker := 0
    for _, num := range nums {
        if num == val {
            cnt++
            continue
        }
        nums[marker] = num
        marker++;
    }
    return len(nums)-cnt
} 