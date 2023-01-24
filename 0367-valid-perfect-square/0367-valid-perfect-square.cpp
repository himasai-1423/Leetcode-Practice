class Solution {
public:
    bool isPerfectSquare(int num) {
        int sq =sqrt(num);
        // cout<<sq<<" " <<sqrt(num)<<endl;
        return (num == sq*sq);
    }
};