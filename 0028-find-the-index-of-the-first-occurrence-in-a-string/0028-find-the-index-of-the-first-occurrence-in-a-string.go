func strStr(haystack string, needle string) int {
    n := len(needle)
    for i:=0; i<len(haystack)+1-n; i++ {
        j := 0
        for j=0; j<n; j++ {
            if haystack[i+j] != needle[j] {
                break
            }
        }
        if j==n {
            return i
        }
    }
    return -1
}

