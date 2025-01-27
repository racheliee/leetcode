class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int tot = accumulate(nums.begin(), nums.end(), 0ll);
        long long int left = 0;
        int ret = 0; 
        int len = nums.size();

        for(int i = 0; i < len-1; ++i){
            left += nums[i];
            tot -= nums[i];

            if(left >= tot)
                ++ret;
        }

        return ret;
    }
};