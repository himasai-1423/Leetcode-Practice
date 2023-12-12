func maxProduct(nums []int) int {
    maxi, secMaxi := 0, 0
    
    for _, num := range nums {
        if num>maxi {
            secMaxi = maxi
            maxi = num
        } else {
            secMaxi = max(secMaxi, num)
        }
    }
    return (maxi-1)*(secMaxi-1)
}