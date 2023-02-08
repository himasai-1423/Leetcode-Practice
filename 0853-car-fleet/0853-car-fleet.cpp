class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v(speed.size(), {0, 0});

        for(int i=0; i<speed.size(); i++){
            v[i].first = position[i];
            v[i].second = speed[i];
        }
        
        sort(v.begin(), v.end(),
             [](const pair<int,int> &a, const pair<int,int> &b) { 
                    return (a.first > b.first);
            });
        
        double time;
        stack<double> st;
        for(int i=0; i<speed.size(); i++){
            time = (double)(target-v[i].first)/v[i].second;
            double prevTime;
            if(!st.empty())
                prevTime = st.top();
            st.push(time);
            if(st.size()>=2 && st.top()<=prevTime){
                st.pop();
            }
        }
        return st.size();
    }
};