func minOperations(s string) int {
    oneOddCnt, zeroEvenCnt := 0, 0
    flag := '1'
    
    for _, i := range s {
        if flag == i {
            oneOddCnt++
        } else {
            zeroEvenCnt++
        }
        
        if flag == '1' {
            flag = '0'
        } else {
            flag = '1'
        }
    }
    return min(zeroEvenCnt, oneOddCnt)
}