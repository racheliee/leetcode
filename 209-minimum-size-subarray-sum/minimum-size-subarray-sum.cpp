class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = (int)nums.size();
        long long sum = 0;
        int ret = 100001; // longer than max length

        for(int i = 0, j = 0; i < len; ++i){
            sum += nums[i];
            while(j <= i && sum >= target){
                ret = min(ret, i-j+1);
                sum -= nums[j++];
            }
        }

        return ret == 100001 ? 0: ret;
    }
};