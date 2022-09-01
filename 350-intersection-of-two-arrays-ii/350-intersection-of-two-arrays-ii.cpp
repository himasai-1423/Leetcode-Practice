class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> res;
        for(int i=0; i<nums1.size(); i++){
            m[nums1[i]]++;
        }
        
        for(int &i: nums2){
            if(m[i]){
                res.push_back(i);
                m[i]--;
            }
        }
        return res;
    }
};