class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int acc = 0, len = prices.size() - 1; // be careful of unsigned - 1

        if (len == 0)
            return 0;

        for (int i = 0; i < len; ++i) {
            int diff = prices[i + 1] - prices[i];
            if (diff > 0)    // keep it if it's risin'
                acc += diff; // buy
            // don't do nothin if it drops 
        }

        return acc;
    }
};