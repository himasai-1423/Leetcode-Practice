class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        priority_queue<int> pq;
        
        for(auto &i: piles) 
            pq.push(i);
        
        int Alice = 0, Bob = 0;
        for(int i=0; i<piles.size(); i++) {
            if(i%2==0) 
                Alice += pq.top();
            else 
                Bob += pq.top();
            pq.pop();
        }
        return Alice>Bob;
    }
};