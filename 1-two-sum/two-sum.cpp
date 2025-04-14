class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();

        for (int i = 0; i < len; ++i) {
            int complement = target - nums[i];

            // 이미 찾은 영역은 또 볼 필요가 없으니까
            auto found = find(nums.begin() + i + 1, nums.end(), complement);
            if (found != nums.end())
                return {i, (int)(found - nums.begin())};
        }

        return vector<int>();
    }
};