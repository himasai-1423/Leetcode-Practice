class Solution {
public:
    int numTrees(int n) {
        vector<int> treesVal(n+1, 1);
        
        for(int i=2; i<=n; i++){
            int totalVal =0;
            for(int j=1; j<=i; j++){
                int left = j -1;
                int right = i - j;
                totalVal += treesVal[left]*treesVal[right];
            }
            treesVal[i] = totalVal;
        }
        return treesVal[n];
    }
};