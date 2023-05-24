class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long curSum = 0, res = 0;
        vector<pair<int, int>> arr;
        
        for(int i=0; i<nums1.size(); i++) 
            arr.push_back({nums2[i], nums1[i]});
        
        sort(arr.rbegin(), arr.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<nums1.size(); i++) {
            curSum += arr[i].second;
            pq.push(arr[i].second);
            
            if(i<k-1) continue;
            
            res = max(res, curSum*arr[i].first);
            curSum -= pq.top();
            pq.pop();
        }
        return res;
    }
};