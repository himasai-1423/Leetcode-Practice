class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> res;
        
        for(int i=0; i<envelopes.size(); i++){
            auto it = lower_bound(res.begin(), res.end(), envelopes[i][1]);
            
            if(it==res.end())
                res.push_back(envelopes[i][1]);
            
            else
                *it = envelopes[i][1];
        }
        return res.size();
    }
};