class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int m = 1e9+7, res=0, n=arr.size();
        stack<int> st;
        
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || arr[st.top()]>=arr[i])){
                int mid = st.top();
                st.pop();
                int left = st.empty()?-1:st.top();
                
                long ans = ((mid-left)*(i-mid))%m;
                ans = (ans * arr[mid])%m;
                res = (res+ans)%m;
            }
            st.push(i);
        }
        return res;
    }
};