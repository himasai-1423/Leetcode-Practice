class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        for(int i=0; i<text.size(); i++){
            if(text[i]=='b' || text[i]=='a' ||text[i]=='l' ||text[i]=='o' ||text[i]=='n' )
                m[text[i]]++;
        }
        int res = 0;
        while(true){
            if(m['b']>=1 && m['a']>=1 && m['l']>=2 && m['o']>=2 && m['n']>=1){
                res++;
                m['b']--;
                m['a']--;
                m['l']-=2;
                m['o']-=2;
                m['n']--;
            }
            
            else
                break;
        }
        return res;
    }
};