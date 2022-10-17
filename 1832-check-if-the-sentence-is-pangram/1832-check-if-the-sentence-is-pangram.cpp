class Solution {
public:
    bool checkIfPangram(string sentence) {
        int seen = 0;
        
        for (auto currChar : sentence) {
            int mappedIndex = currChar - 'a';

            int currBit = 1 << mappedIndex;

            seen |= currBit;
        }
        return seen == (1 << 26) - 1;
    }
};