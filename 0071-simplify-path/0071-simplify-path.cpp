class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        stack<string> st;
        int i=0;
        
        for(int i = 0;  i<path.size(); ++i) {
            if(path[i]=='/') continue;
            
            string cur="";
            while(i<path.size() && path[i]!='/') {
                cur+=path[i];
                i++;
            }
            cout<<cur<<endl;
            
            if(cur==".") continue;
            
            else if(cur == ".."){
                if(!st.empty())
                    st.pop();
            }
            
            else st.push(cur);
        }
        
        while(!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        
        return res.size()==0?"/":res;
    }
};