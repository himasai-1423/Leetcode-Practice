func maxWidthOfVerticalArea(points [][]int) int {
    sort.Slice(points, func(i, j int) bool {
        return points[i][0]<points[j][0]
    })
    
    res := 0
    for i:=1; i<len(points); i++ {
        res =max(res, points[i][0]-points[i-1][0])
    }
    
    return res
}