class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res(score.size(), "");
        priority_queue<pair<int, int>> q;
        
        for(int i=0; i<score.size(); i++)
            q.push({score[i], i});
        
        int ctr=0;
        
        while(!q.empty()) {
            ctr++;
            auto val = q.top();
            q.pop();
            if(ctr==1)
                res[val.second] = "Gold Medal";
            
            else if(ctr==2)
                res[val.second] = "Silver Medal";
            
            else if(ctr==3)
                res[val.second] = "Bronze Medal";
            
            else
                res[val.second] = to_string(ctr);
        }
        return res;
    }
};