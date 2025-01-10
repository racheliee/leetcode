class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> max_freq(26, 0);
        for (const string& word : words2) {
            vector<int> freq(26, 0);
            for (char c : word) {
                ++freq[c - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                max_freq[i] = max(max_freq[i], freq[i]);
            }
        }
        vector<string> ret;
        for (const string& word : words1) {
            vector<int> freq(26, 0);
            for (char c : word) {
                ++freq[c - 'a'];
            }

            bool is_universal = true;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] < max_freq[i]) {
                    is_universal = false;
                    break;
                }
            }

            if (is_universal) {
                ret.push_back(word);
            }
        }

        return ret;
    }
};
