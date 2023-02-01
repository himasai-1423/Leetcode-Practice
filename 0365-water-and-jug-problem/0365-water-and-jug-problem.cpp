class Solution {
public:
    bool canMeasureWater(int x, int y, int targetCapacity) {
        int z = x+y;
        if(z<targetCapacity) return false;
        
        int steps[] = {x, -x, y, -y};
        queue<int> q;
        q.push(0);
        
        vector<int> visited(z+1, 0);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int i=0; i<4; i++){
                int newNode = node + steps[i];
                
                if(newNode == targetCapacity) return true;
                
                if(newNode>=0 && newNode<=z && visited[newNode]==0){
                    q.push(newNode);
                    visited[newNode] = 1;
                }
            }
        }
        return false;
    }
};