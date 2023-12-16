func isAnagram(s string, t string) bool {
    m := make(map[rune]int)

    if len(s) != len(t) {
        return false
    }

    for _, char := range s {
        m[char]++
    }

    for _, char := range t {
        m[char]--
    }
    
    for _, elem := range m {
        if elem != 0 {
            return false
        } 
    }
    return true
}