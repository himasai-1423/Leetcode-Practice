class Solution {
public:
    int traverse(int n, string &s, int row, int col, int pos) {
        int ans=0;
        for(int i=pos; i<s.size(); i++) {
            if(s[i]=='L')
                col--;
            else if(s[i]=='R')
                col++;
            else if(s[i]=='U')
                row--;
            else
                row++;
            
            if(row>=n || col>=n || row<0 || col<0)
                return ans;
            ans++;
        }
        return ans;
    }
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> res(s.size(), 0);
        
        for(int i=0; i<s.size(); i++) 
            res[i] = traverse(n, s, startPos[0], startPos[1], i);
        
        return res;
    }
};