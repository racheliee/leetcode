class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int r = (int)nums.size()-1, l = 0;

        while(l < r) {
            int mid = (l + r) / 2;

            if(mid % 2) --mid; // make mid even

            if(nums[mid] == nums[mid+1])
                l = mid + 2;
            else
                r = mid;
        }

        return nums[l];        
    }
};