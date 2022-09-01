class Solution {
public:
    int searchItem(vector<int> &v, int t, vector<int> &ans){
        int s = 0, m, e = v.size() - 1;
        while (s <= e)
        {
            m = s + (e - s) / 2;
            if (v[m] == t)
            {
                ans.push_back(v[m]);
                v.erase(v.begin() + m);
                break;
            }
            if (v[m] < t)
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }
        return 0;
    }
    vector<int> intersect(vector<int> &n1, vector<int> &n2)
    {
        vector<int> ans;
        sort(n1.begin(), n1.end());
        for (auto i : n2)
        {
            searchItem(n1, i, ans);
        }
        return ans;
    }
};