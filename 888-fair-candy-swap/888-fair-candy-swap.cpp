class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aSum=0, bSum=0;
        for(int i:aliceSizes) aSum += i;
        for(int i:bobSizes) bSum += i;
        
        int ans = (aSum - bSum)/2;
        
        set<int> s;
        for(int j: aliceSizes) {
            s.insert(j);
        }
        
        for(int k: bobSizes){
            if(s.count(k+ans)>0) return {k+ans, k};
        }
        return vector<int>();
    }
};