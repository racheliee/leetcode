class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = (int)A.size();
        map<int, int> m;

        vector<int> ret(n);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            ++m[A[i]];
            ++m[B[i]];
            if (m[A[i]] == 2)
                ++cnt;
            if (m[B[i]] == 2)
                ++cnt;
            if (A[i] == B[i])
                --cnt;
            ret[i] = i == 0 ? cnt : ret[i - 1] + cnt;
            cnt = 0;
        }

        return ret;
    }
};