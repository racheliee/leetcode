class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> m(26, 0);

        for (char& c : magazine)
            ++m[c - 97];

        for (char& c : ransomNote) {
            --m[c - 97];
            if (m[c - 97] < 0)
                return false;
        }

        return true;
    }
};