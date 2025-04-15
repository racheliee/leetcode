class Solution {
public:
    Solution(vector<int>& w) {
        int len = w.size();
        prefix_sums.resize(len);

        prefix_sums[0] = w[0];
        for(int i = 1; i < len; ++i) {
            prefix_sums[i] = prefix_sums[i-1] + w[i];
        }
    }
    
    int pickIndex() {
        int randn = rand() % prefix_sums.back(); // random in [1, total]
        auto it = upper_bound(prefix_sums.begin(), prefix_sums.end(), randn);

        return it - prefix_sums.begin();
    }

private:
    vector<int> prefix_sums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */