class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int len = (int)nums.size();
        
        if(len == 1) return 0;

        sort(nums.begin(), nums.end());

        int p = 0, q = len -1;
        int count = 0;
        int sum;
        while (p < q) {
            sum = nums[p] + nums[q];

            if(sum == k) { // no need to remove elements from vector
                count++;
                ++p;
                --q;
            }
            else if(sum > k){
                --q;
            } else {
                ++p;
            }
        }

        return count;
    }
};