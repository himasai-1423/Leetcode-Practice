class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<int> q;
        long long res = 0;
        
        for(int i=0; i<reward1.size(); i++) {
            q.push(reward1[i]-reward2[i]);
            res += reward2[i];
        }
        
        while(k) {
            k--;
            res += q.top();
            q.pop();
        }
        return res;
    }
};