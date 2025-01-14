class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = (int)A.size();

        unordered_map<int, int> m;
        vector<int> ret(n);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            ++m[A[i]];
            ++m[B[i]];
            for (auto it = m.begin(); it != m.end(); ++it) {
                // cout << "num " << it->first << " occurs " << it->second <<
                // endl;
                if (it->second == 2)
                    ++cnt;
            }
            ret[i] = cnt;
            cnt = 0;
        }

        return ret;
    }
};