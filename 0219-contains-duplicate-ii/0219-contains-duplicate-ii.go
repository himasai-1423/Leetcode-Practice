func containsNearbyDuplicate(nums []int, k int) bool {
    m := make(map[int]int)
    for i, num := range nums {
        if val, ok := m[num]; ok {
            if i-val <= k {
                return true
            }
        }
        m[num] = i
    }
    return false
}