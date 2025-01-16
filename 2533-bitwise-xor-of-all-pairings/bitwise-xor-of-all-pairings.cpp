class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;

        if (nums2.size() % 2 == 1) {
            for (int num : nums1) {
                result ^= num;
            }
        }

        if (nums1.size() % 2 == 1) {
            for (int num : nums2) {
                result ^= num;
            }
        }
        return result;
    }
};