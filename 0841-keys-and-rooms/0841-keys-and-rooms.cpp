class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        
        queue<int> availableKeys;
        availableKeys.push(0);
        visited[0] = true;
        
        while(!availableKeys.empty()){
            int toVisit = availableKeys.front();
            availableKeys.pop();
            
            for(int i : rooms[toVisit]){
                if(!visited[i]){
                    availableKeys.push(i);
                    visited[i] = true;
                }
            }
        }

        for(auto i: visited)
            if(!i)
                return false;

        return true;
    }
};