func findSpecialInteger(arr []int) int {
    var quarter int
    quarter = len(arr)/4
    cnt := 1
    
    for i:=1; i<len(arr); i++ {
        if arr[i-1] == arr[i] {
            cnt++
            if cnt>quarter {
                return arr[i-1]
            }
        } else {
            cnt = 1
        }
    }
    return arr[0]
}