class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int, int> res = {0, 0};
        
        for(int i=0; i<moves.size(); i++) {
            if(moves[i]=='U') 
                res.first++;
            else if(moves[i]=='D') 
                res.first--;
            else if(moves[i]=='L') 
                res.second++;
            else if(moves[i]=='R') 
                res.second--;
        }
        
        if(res.first==0 && res.second == 0)
            return true;
        
        return false;
    }
};