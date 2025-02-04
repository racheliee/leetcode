class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ret = nums[0];
        int curr = nums[0];
        int len = nums.size();

        for(int i = 1; i < len; ++i){
            if(nums[i] > nums[i-1])
                curr += nums[i];
            else{
                ret = max(curr, ret);
                curr = nums[i];
            }
        }

        return max(ret, curr);
    }
};