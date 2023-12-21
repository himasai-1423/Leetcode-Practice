func buyChoco(prices []int, money int) int {
    firstMin, secondMin := math.MaxInt, math.MaxInt
    
    for _,price := range prices {
        if firstMin>price {
            secondMin = firstMin
            firstMin = price
        } else if secondMin>price {
            secondMin = price
        }
    }
    
    if money-firstMin-secondMin<0 {
        return money
    }
    
    return money-firstMin-secondMin
}