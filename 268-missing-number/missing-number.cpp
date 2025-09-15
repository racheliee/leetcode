class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n;
        for (int i = 0; i < n; ++i)
            res ^= (i ^ nums[i]);
        
        return res;
    }
};

/*
1. if XOR-ed with 0, return same number: 5^ 0 = 5

2. if XOR w same number, return 0: 5^5 = 0;

3. XOR 2 diff numbers, return nothing: 4 ^ 5 = 5 ^ 4

SO basically,
O ^ O ^ 1 ^ 1 ^ 2 ^ 3 ^ 3
everything cancels out but 2

ot you can use gaussian sum
*/