class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();

        if(len <= 2) return len;
        
        int k = 2;
        for(int i = 2; i < len; ++i)
            if(nums[i] != nums[k-2]) 
                nums[k++] = nums[i];

        return k;
    }
};