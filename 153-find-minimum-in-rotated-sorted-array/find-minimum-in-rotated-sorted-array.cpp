class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            // [0 1 2 3 4]  [5 6 7 8 9] --> needs the 2nd condition to work
            // [8 9 0 1 2]  [3 4 5 6 7]
            if (nums[left] > nums[mid] || nums[left] < nums[right])
                right = mid;
            else
                left = mid + 1;
        }

        return nums[left];
    }
};