class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int left, right, sum;
        int len = nums.size()-2;
        vector<vector<int> > ret;

        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < len; ++i){
            // skip duplicates
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            left = i+1; right = len+1;

            while (left < right){
                sum = nums[i] + nums[left] + nums[right];

                if(sum == 0){
                    ret.push_back({nums[i], nums[right], nums[left]});

                    while(left < right && nums[left] == nums[left + 1])
                        ++left;
                    while(left < right && nums[right] == nums[right - 1])
                        --right;

                    ++left;
                    --right;
                }
                else if(sum < 0){
                    ++left;
                }else {
                    --right;
                }
            }
        }

        return ret;
    }
};