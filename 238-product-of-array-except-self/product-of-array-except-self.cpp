#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mult = 1;
        int zeroes = 0;
        int len = (int)nums.size();

        for(int i = 0; i < len; ++i){
            if(nums[i]) mult *= nums[i];
            else {
                zeroes++;
                if(zeroes > 1){
                    vector<int> v(len, 0);
                    return v;
                }
            }
        }

        for(int i = 0; i < len; ++i){
            if(nums[i] == 0) nums[i] = mult;
            else nums[i] = zeroes ? 0:  (int)(mult / nums[i]);
        }

        return nums;
    }
};
