func lastStoneWeight(stones []int) int {
	q := &MaxHeap{}

	for i := 0; i < len(stones); i++ {
		heap.Push(q, stones[i])
	}

	for len(*q) > 1 {
		last := heap.Pop(q).(int)
		newLast := heap.Pop(q).(int)
		heap.Push(q, last-newLast)
	}

	return (*q)[0]
}

// Copied from https://golang.org/pkg/container/heap/ 
type MaxHeap []int

func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h MaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MaxHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *MaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

