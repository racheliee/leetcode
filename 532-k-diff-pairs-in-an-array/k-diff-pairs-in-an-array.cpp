class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(const auto& n: nums) ++m[n];

        int ret = 0;
        for(const auto& [n, v]: m) {
            if(m.count(n+k)){
                if(n == n+k && v < 2) continue; 
                ++ret;
            }
        }
        return ret;
    }
};