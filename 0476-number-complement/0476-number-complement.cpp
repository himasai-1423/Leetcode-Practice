class Solution {
public:
    int findComplement(int num) {
        int count=1;
        
        while(count<num){
            count = (count<<1)| 1;
        }
        
        return num^count;
    }
};