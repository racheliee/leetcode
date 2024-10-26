class Solution {
  public:
    bool increasingTriplet(vector<int> &nums) {
        int len = (int)nums.size();

        if (len < 3)
            return false;

        int first = INT32_MAX;
        int second = INT32_MAX;

        for (int n : nums) {
            if (n > second)
                return true;

            if (n <= first)
                first = n;
            else
                second = n;
        }

        return false;
    }
};