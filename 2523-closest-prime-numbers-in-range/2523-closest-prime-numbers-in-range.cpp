class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int a = -1, b=-1; 
        bool seen[1000001]={};
        vector<int> res(2, -1); 
        seen[1] = seen[0]= true; 
        
        for(int i=2; i<=right; i++)
            if(!seen[i])
                for(int j=2*i; j<=right; j+=i)
                    seen[j] = true;
            
        for(int i=left; i<=right; i++){
            if(!seen[i]){
                b = a;
                a = i;
                if(res[1]==-1 || (a-b)<(res[1]-res[0])){
                    res[0] = b;
                    res[1] = a;
                    if(res[1]-res[0]<3)
                        break;
                }
            }
        }
        
        if(res[0]==-1){
            res[1]=-1;

            return res;
        }        
        return res;
    }
};