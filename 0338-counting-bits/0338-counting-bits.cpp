class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        
        for(int i=0; i<=n; i++){
            int a = __builtin_popcount(i);
            res.push_back(a);
        }
        return res;
    }
};