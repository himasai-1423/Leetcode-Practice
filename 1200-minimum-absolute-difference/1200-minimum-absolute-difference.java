class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        List<List<Integer>> res = new ArrayList();
        
        Arrays.sort(arr);
        
        int mini = Integer.MAX_VALUE;
        for(int i=1; i<arr.length; i++)
            mini = Math.min(arr[i]-arr[i-1], mini);
        
        for(int i=1; i<arr.length; i++){
            if(arr[i]-arr[i-1] == mini){
                List<Integer> vec = new ArrayList();
                vec.add(arr[i-1]);
                vec.add(arr[i]);
                res.add(vec);
            }
        }
        return res;
    }
}