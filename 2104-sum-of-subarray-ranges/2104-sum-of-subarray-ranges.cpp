class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res=0, n= nums.size();
        stack<int> st;
        
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || nums[st.top()]>nums[i])){
                int mid = st.top();
                st.pop();
                int left = (st.empty()?-1:st.top());
                
                long long ans = (long long)(mid-left)*(i-mid)*nums[mid];
                
                res -= ans;
            }
            st.push(i);
        }
        
        st = stack<int>();
        
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || nums[st.top()]<nums[i])){
                int mid = st.top();
                st.pop();
                int left = (st.empty()?-1:st.top());
                
                long long ans = (long long)(mid-left)*(i-mid)*nums[mid];
                
                res += ans;
            }
            st.push(i);
        }
        return res;
    }
};