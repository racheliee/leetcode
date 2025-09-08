class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> m;

        for(int i = 0; i < nums.size(); ++i) {
            if(m.count(nums[i]) && m[nums[i]] > 1) {
                nums.erase(nums.begin() + i);
                --i;
            }
            ++m[nums[i]];
        }

        return nums.size();
    }
};