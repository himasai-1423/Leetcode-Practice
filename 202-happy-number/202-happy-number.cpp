class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int val=n;
        while(val!=1){
            if(s.find(val)==s.end()) s.insert(val);
            else return false;
            
            int rem=0, sum=0;
            while(val){
                rem = val%10;
                sum += (rem*rem);
                val /= 10;
            }
            val = sum;
        }
        return true;
    }
};