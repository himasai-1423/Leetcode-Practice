class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> res(nums1.size(), -1);
        unordered_map<int, int> m;
        
        for(int i=0; i<nums2.size(); i++) {
            while(!st.empty() && nums2[i]>st.top()) {
                m[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        for(int i=0; i<nums1.size(); i++) 
            if(m.count(nums1[i])) 
                res[i] = m[nums1[i]];
            
        return res;
    }
};