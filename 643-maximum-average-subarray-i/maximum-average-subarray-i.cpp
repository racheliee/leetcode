class Solution {
  public:
    double findMaxAverage(vector<int> &nums, int k) {
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);

        int len = (int)nums.size();
        if (k == len)
            return (double)sum/k;

        int max = sum;
        for (int i = k; i < len; ++i) {
            sum += nums[i];
            sum -= nums[i - k];

            if (sum > max)
                max = sum;
        }

        return (double)max / k;
    }
};