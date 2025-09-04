class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int len = nums.size();
        if(!len) return ret;
        
        int prev = nums[0];
        for(int i = 0; i < len; ++i) {
            if(i + 1 < len && (long long)nums[i] - (long long)nums[i+1] == -1) continue;

            if(prev == nums[i])
                ret.push_back(to_string(prev));
            else
                ret.push_back(to_string(prev) + "->" + to_string(nums[i]));
            
            if(i + 1 < len)
                prev = nums[i+1];
        }

        return ret;
    }
};