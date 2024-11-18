class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curr_max = 0, curr_min = 0;
        int gmax = nums[0], gmin = nums[0];
        int tot = 0;

        // 전체의 합에서 최소를 빼면 circular로 도는거까지 고려 가능
        for(int n: nums){
            curr_max = max(curr_max + n, n);
            curr_min = min(curr_min + n, n);
            gmax = max(curr_max, gmax);
            gmin = min(curr_min, gmin);
            tot += n;
        }

        return gmax > 0 ? max(gmax, tot-gmin) : gmax;
    }
};