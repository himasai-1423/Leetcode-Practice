class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> res(cars.size(), -1);
        stack<int> st;
        
        for(int i=cars.size()-1; i>=0; i--){
            int curPos = cars[i][0], curSpeed = cars[i][1];
            
            while(!st.empty()){
                int j = st.top(), leadPos = cars[j][0], leadSpeed = cars[j][1];
                
                if(curSpeed<=leadSpeed || (double)(leadPos-curPos)/(curSpeed-leadSpeed) >= res[j] 
                   && res[j]>0)
                    st.pop();
                
                else 
                    break;
            }
            
            if(!st.empty())
                res[i] = (double)(cars[st.top()][0]-curPos)/(curSpeed-cars[st.top()][1]);
            
            st.push(i);
        }
        return res;
    }
};