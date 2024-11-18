class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = (int)nums.size();
        int left = 0, right = len-1;
        int mid;
        while(left <= right){
            mid = left + (right-left)/2;

            if(mid > 0 && nums[mid-1] > nums[mid])
                right = mid - 1;
            else if(mid < len-1 && nums[mid+1] > nums[mid])
                left = mid + 1;
            else
                return mid;

        }

        return 0;
    }
};