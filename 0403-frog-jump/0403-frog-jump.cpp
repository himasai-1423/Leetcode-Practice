class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, set<int>> m;
        
        for(int i=0; i<stones.size(); i++){
            m[stones[i]].insert(0);
        }
        
        m[stones[0]].insert(1);
        
        for(int i=0; i<stones.size(); i++){
            int curStone = stones[i];
            set<int> jumps = m[curStone];
            for(auto jump : jumps){
                if(jump==0) continue;
                
                int pos = curStone + jump;
                if(pos == stones[stones.size()-1])
                    return true;
                
                if(m.find(pos) != m.end()){
                    if(jump-1>0){
                        m[pos].insert(jump-1);
                    }
                    m[pos].insert(jump);
                    m[pos].insert(jump+1);
                }
            }
        }
        return false;
    }
};