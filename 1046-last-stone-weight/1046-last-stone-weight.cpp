class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        
        for(int i=0; i<stones.size(); i++) 
            q.push(stones[i]);
        
        while(q.size()>1) {
            int last = q.top();
            q.pop();
            int lastSecond = q.top();
            q.pop();
            
            q.push(last-lastSecond);
        }
        
        return q.size()==0?0:q.top();
    }
};