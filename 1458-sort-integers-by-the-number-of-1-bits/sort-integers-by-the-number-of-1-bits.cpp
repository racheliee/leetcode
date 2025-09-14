class Solution {
public:
    static int num1Bits(int n) {
        string binary = bitset<14>(n).to_string();
        int cnt = 0;
        for(const auto& c: binary) cnt = c == '1' ? cnt + 1 : cnt;
        return cnt;
    }

    static bool customCompare(const int& a, const int& b) {
        int an = num1Bits(a), bn = num1Bits(b); 
        if(an == bn) return a < b;
        return an < bn;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), customCompare);
        return arr;
    }
};