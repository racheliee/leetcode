class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k)
            return false;

        if (s.length() == k)
            return true;

        vector<char> freq(26, 0);

        for (char& c : s) {
            ++freq[c - 'a'];
        }

        int odd_count = 0;
        for (auto& cnt: freq) {
            if (cnt % 2 == 1)
                ++odd_count;
        }

        return odd_count <= k ? true : false;
    }
};