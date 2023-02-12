class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> p(position.size(), {0, 0});
        
        for(int i=0; i<position.size(); i++){
            p[i].first = position[i];
            p[i].second = speed[i];
        }
        
        sort(p.begin(), p.end(), []
             (pair<int, int> &a, pair<int, int> &b){
                 return (a.first>b.first);
             }
            );
        
        stack<double> st;
        double topPrev;
        for(int i=0; i<position.size(); i++){
            if(!st.empty())
                topPrev=st.top();
            double time = (double)(target-p[i].first)/p[i].second;
            st.push(time);
            
            if(st.size()>=2 && st.top()<=topPrev)
                st.pop();
        }
        return st.size();
    }
};