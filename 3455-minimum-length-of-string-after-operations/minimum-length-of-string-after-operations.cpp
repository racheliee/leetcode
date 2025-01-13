class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            ++freq[c - 'a'];
        }

        int ret = 0;
        for (int& n : freq) {
            if (n)
                ret += n % 2 == 0 ? 2 : 1;
        }
        return ret;
    }
};