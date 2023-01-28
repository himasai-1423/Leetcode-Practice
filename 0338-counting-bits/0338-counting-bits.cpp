class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        
        for(int i=0; i<=n; i++){
            int a=0, j=31;
            while(i!=0 && j>=0){
                if(((i>>j)&1)==1) a++;
                j--;
            }
            res.push_back(a);
        }
        return res;
    }
};