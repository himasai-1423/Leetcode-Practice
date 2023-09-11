class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int ans = 0;
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<arr.size(); i++) {
            int l = i+1, r=arr.size()-1;
             int MOD = 1e9+7;
            int T = target - arr[i];
            while(l<r) {
                if(arr[l]+arr[r] < T)
                    l++;
                else if(arr[l]+arr[r] > T)
                    r--;
                else if(arr[l] != arr[r]) {
                    int left = 1, right = 1;
                     while (l+1 < r && arr[l] == arr[l+1]) {
                        left++;
                        l++;
                    }
                    while (r-1 > l && arr[r] == arr[r-1]) {
                        right++;
                        r--;
                    }
                    ans += left * right;
                    ans %= MOD;
                    l++;
                    r--;
                } else {
                    ans += (r-l+1) * (r-l) / 2;
                    ans %= MOD;
                    break;
                }
            }
        }
        return ans;
    }
};