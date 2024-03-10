func intersection(nums1 []int, nums2 []int) []int {
    s := make(map[int]struct{})
    var res []int
    
    for _, num1 := range nums1 {
        s[num1] = struct{}{}
    }
    
    for _, num := range nums2 {
        if _, found := s[num]; found {
            res = append(res, num)
            delete(s, num)
        }
    }
    return res
}