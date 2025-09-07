class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> sum(n);

        int neg = 0;
        for(int i = 1; i < n; ++i) {
            sum[i-1] = i;
            neg -= i;
        }
        sum[n-1] = neg;

        return sum;
    }
};