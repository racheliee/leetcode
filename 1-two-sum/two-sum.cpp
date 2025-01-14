class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        int len = nums.size(), complement;

        for(int i = 0; i < len; ++i){
            complement = target - nums[i];

            if(m.find(complement) != m.end())
                return {i, m[complement]};

            m[nums[i]] = i;
        }

        return {};
    }
};