class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' ||
            c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
            return true;
        return false;
    }
    string sortVowels(string s) {
        vector<int> indices;
        vector<char> vowels;
        int len = s.length();

        for (int i = 0; i < len; ++i) {
            if (isVowel(s[i])) {
                indices.push_back(i);
                vowels.push_back(s[i]);
            }
        }

        sort(vowels.begin(), vowels.end());

        string ret = "";
        int idx = 0;
        int vlen = indices.size();
        for (int i = 0; i < len; ++i) {
            if (idx < vlen && i == indices[idx]) {
                ret += vowels[idx++];
            } else {
                ret += s[i];
            }
        }

        return ret;
    }
};