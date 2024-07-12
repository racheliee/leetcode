class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        unordered_map<int, int> num_map;

        int len = nums.size(), complement;

        // find two sums
        for (int i = 0; i < len; ++i) {
            complement = target - nums[i];

            if (num_map.count(complement)) {
                return {i, num_map[complement]};
            }

            num_map[nums[i]] = i;
        }

        return {};
    }
};