class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ret = (int)nums.size();
        
        for(int i = 0; i < ret; ++i){
            if(nums[i] == val){
                nums[i--] = nums[--ret];
            }
        }

        return ret;
    }
};