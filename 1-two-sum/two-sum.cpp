class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;

        int len = nums.size();
        for(int i = 0; i < len; ++i){
            for(int j = i+1; j < len; ++j){
                if(nums[i] + nums[j] == target){
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
            }
        }

        return v;
    }
};