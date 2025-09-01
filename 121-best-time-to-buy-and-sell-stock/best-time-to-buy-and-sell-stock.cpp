class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0, len = prices.size(), m = prices[0], curr = 0;

        for(int i = 1; i < len; ++i) {
            curr = prices[i] - m;

            ret = max(ret, curr);
            m = min(m, prices[i]);
        }

        return ret > 0 ? ret : 0;
    }
};