class Solution {
public:
    vector<string> res;
    
    void buildParenthesis(string &s, int open, int close){
        if(open == 0 and close ==0){
            res.push_back(s);
            return;
        }
        
        if(open!=0){
            s.push_back('(');
            buildParenthesis(s, open-1, close);
            s.pop_back();
        }
        
        if(close>open && close!=0){
            s.push_back(')');
            buildParenthesis(s, open, close-1);
            s.pop_back();
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        string s;
        buildParenthesis(s, n, n);
        
        return res;
    }
};