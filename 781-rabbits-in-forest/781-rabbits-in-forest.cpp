class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m; 
        int rabbits=0;
                
        for(int a : answers){
            if(a==0)
                rabbits++;
            else{   
                if(m[a]==0)
                    rabbits+=a+1;
                m[a]++;
                if(m[a]==a+1)
                    m[a]=0;
            }
        }
        return rabbits;
    }
};