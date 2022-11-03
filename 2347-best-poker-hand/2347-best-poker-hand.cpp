class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        string s;
        unordered_map<int, int> mR;
        unordered_map<char, int> mS;
        int maxi = INT_MIN;
        for(int i=0; i<5; i++){
            mS[suits[i]]++;
            mR[ranks[i]]++;
            maxi = max(maxi, mR[ranks[i]]);
        }
        
        if(mS.size()==1) s="Flush";
        else if(maxi>=3) s="Three of a Kind";
        else if(maxi==2) s="Pair";
        else s="High Card";
        
        return s;
    }
};