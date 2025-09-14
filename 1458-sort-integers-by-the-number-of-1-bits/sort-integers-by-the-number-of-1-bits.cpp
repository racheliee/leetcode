class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int an = __builtin_popcount(a), bn = __builtin_popcount(b);
            return an == bn ? a < b : an < bn;
        });
        return arr;
    }
};