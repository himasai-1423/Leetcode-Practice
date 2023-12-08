func totalMoney(n int) int {
    k := int(n/7)
    F := 28
    L := 28 + (k-1)*7
    arithmeticSum := int(k * (F+L)/2)
    
    mondayVal := k + 1
    finalWeek := 0
    
    for i:=0; i<(n%7); i++ {
        finalWeek += mondayVal + i
    }
    
    return finalWeek + arithmeticSum
}