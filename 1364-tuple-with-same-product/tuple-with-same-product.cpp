class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> freq;
        int len = nums.size();

        for(int i = 0; i < len; ++i) {
            for(int j = i + 1; j < len; ++j){
                ++freq[nums[i]*nums[j]];
            }
        }

        int ret = 0;
        for(auto it = freq.begin(); it != freq.end(); ++it){
            if(it->second > 1){
                ret += 8 * ((it->second)*(it->second-1))/2;
            }
        }

        return ret;
    }
};