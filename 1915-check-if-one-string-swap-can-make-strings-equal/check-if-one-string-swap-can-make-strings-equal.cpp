class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;

        vector<int> s1map(26, 0);
        vector<int> s2map(26, 0);
        int len = s1.length();

        int num_diff = 0;
        for (int i = 0; i < len; ++i) {
            if (s1[i] != s2[i]) {
                num_diff++;
                if (num_diff > 2)
                    return false;
            }
            ++s1map[s1[i] - 'a'];
            ++s2map[s2[i] - 'a'];
        }

        // needed for when num_diff is less than 3
        for (int i = 0; i < 26; ++i) {
            if (s1map[i] != s2map[i])
                return false;
        }

        return true;
    }
};