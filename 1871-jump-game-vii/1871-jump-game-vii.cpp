class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.size()-1]=='1')
            return false;
        
        queue<int> q;
        q.push(0);
        
        int farthestJump = 0;
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            int j = max(i+minJump, farthestJump+1);
            while(j<=i+maxJump && j<s.size()) {
                if(s[j]=='0')
                    q.push(j);
                if(j==s.size()-1) 
                    return true;
                j++;
            }
            farthestJump = i + maxJump;
        }
        return false;
    }
};