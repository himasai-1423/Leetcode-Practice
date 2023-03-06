class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j =1, i=0, res = 1;
        
        while(k && i<arr.size()) {
            if(j<arr[i]) {
                res = j;
                k--;
            }
            else
                i++;
            j++;
        }
        
        while(k) {
            res = j;
            k--;
            j++;
        }
        
        return res;
    }
};