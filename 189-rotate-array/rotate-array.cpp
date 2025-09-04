class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        // reverse the array!!
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k % len);
        reverse(nums.begin() + k % len, nums.end());
    }
};

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int len = nums.size();
//         vector<int> temp(len);
//         for(int i = 0; i < len; ++i) 
//             temp[(i+k)%len] = nums[i];
//         nums = temp;
//     }
// };