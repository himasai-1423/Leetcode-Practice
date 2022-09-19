class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int cnt = 0;
        for(int i = 0; i <= s.length() - k; i++)
        {
            int part = stoi(s.substr(i,k));
            if(part && (num%part == 0))
                cnt++;
        }
        return cnt;
    }
};