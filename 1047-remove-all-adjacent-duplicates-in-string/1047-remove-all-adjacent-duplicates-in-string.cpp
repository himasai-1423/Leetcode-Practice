class Solution {
public:
    string removeDuplicates(string s) {
        int curr=0;
        
        for(int i=0; i<s.size(); i++){
            s[curr]=s[i];
            if(curr>0 && s[curr] == s[curr-1])
                curr=curr-2;
            curr++;
        }
        return s.substr(0,curr);
    }
};