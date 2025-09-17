class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MOD = 1e9 + 7;
        vector<int> v(101);
        for (const int& n : arr)
            ++v[n];
        int len = (int)arr.size(), res = 0;

        for (int a = 0; a <= 100; ++a) {
            for (int b = a; b <= 100; ++b) {
                int c = target - a - b;
                if (c < 0 || c > 100)
                    continue;
                if (b > c)
                    continue;

                if (a == b && b == c) {
                    res =
                        (res + (long long)v[a] * (v[a] - 1) * (v[a] - 2) / 6) %
                        MOD;
                } else if (a == b && b != c) {
                    res = (res + (long long)v[a] * (v[a] - 1) / 2 * v[c]) % MOD;
                } else if (a < b && b == c) {
                    res = (res + (long long)v[b] * (v[b] - 1) / 2 * v[a]) % MOD;
                } else if (a < b && b < c) {
                    res = (res + (long long)v[a] * v[b] * v[c]) % MOD;
                }
            }
        }

        return res;
    }
};