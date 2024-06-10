 var m = map[rune]int{
        '(': 1,
        '{': 2,
        '[': 3,
        ')': -1,
        '}': -2,
        ']': -3,
    }

func isValid(s string) bool {
    var st []rune
    for _, ch := range s {
        if m[ch] > 0 {
            st = append(st, ch)
        } else {
            if len(st)<=0 {
                return false
            }
            top := st[len(st)-1]
            st = st[:len(st)-1]
            if m[top] + m[ch] != 0 {
                return false
            }
        }
    }
    return len(st)==0
}