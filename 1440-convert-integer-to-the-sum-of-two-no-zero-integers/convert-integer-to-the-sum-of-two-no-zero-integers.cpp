class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n/2 + 1; ++i) {
            if(!to_string(i).contains("0") && !to_string(n-i).contains("0"))
                return {i, n-i};
        }
        return {1, n-1};
    }
};