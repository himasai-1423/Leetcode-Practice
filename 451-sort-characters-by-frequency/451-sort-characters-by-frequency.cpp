class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        vector<pair<int, char>> p;
        
        string ans;
        
        for(auto &i: s) m[i]++;
        
        for(auto &i: m){
            p.push_back({i.second, i.first});
        }
        
        sort(p.begin(), p.end(), greater<>());
        
        for(auto &i: p){
            while(i.first){
                ans.push_back(i.second);
                i.first--;
            }
        }
        return ans;
    }
};