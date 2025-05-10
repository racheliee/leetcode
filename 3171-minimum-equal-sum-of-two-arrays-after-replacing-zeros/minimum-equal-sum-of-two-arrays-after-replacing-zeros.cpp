class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = accumulate(nums1.begin(), nums1.end(), 0L);
        long long s2 = accumulate(nums2.begin(), nums2.end(), 0L);

        long long z1 = ranges::count(nums1, 0);
        long long z2 = ranges::count(nums2, 0);

        if (!z1 && s1 < s2 + z2)
            return -1;
        if (!z2 && s2 < s1 + z1)
            return -1;
        return max(z1 + s1, z2 + s2);
    }
};