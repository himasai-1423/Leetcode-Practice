class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& A) {
        int n = A.size();
        vector<int> res(n, -1);
        stack<int> s;
        for (int i = 0; i < n * 2; ++i) {
            while (s.size() && A[s.top()] < A[i % n]) {
                res[s.top()] = A[i % n];
                s.pop();
            }
            s.push(i % n);
        }
        return res;
    }
};