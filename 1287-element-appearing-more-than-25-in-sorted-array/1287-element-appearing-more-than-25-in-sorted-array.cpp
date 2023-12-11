class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int quarter = arr.size()/4;
        int cnt=1;
        
        for(int i=1; i<arr.size(); i++) {
            if(arr[i-1]==arr[i]) {
                cnt++;
                if(cnt>quarter) 
                    return arr[i-1];
            }
            else {
                cnt = 1;
            }
        }
        return arr[0];
    }
};