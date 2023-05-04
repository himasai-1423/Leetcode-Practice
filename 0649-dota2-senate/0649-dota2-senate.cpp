class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rQ, sQ;
        
        for(int i=0; i<senate.size(); i++) 
            senate[i]=='R'?rQ.push(i):sQ.push(i);
        
        while(!rQ.empty() && !sQ.empty()) {
            int a = rQ.front(), b = sQ.front();
            rQ.pop();
            sQ.pop();
            if(a<b)
                rQ.push(a+senate.size());
            else
                sQ.push(b+senate.size());
        }
        
        if(rQ.size()>sQ.size())
            return "Radiant";
        return "Dire";
    }
};