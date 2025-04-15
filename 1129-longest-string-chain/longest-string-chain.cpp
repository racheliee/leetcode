class Solution {
public:
    int dfs(vector<string>& words, string str) {
        int len = str.length();
        if (len <= 0)
            return 0;

        // if memoized, return
        if (memo[word_ht[str]] != 0)
            return memo[word_ht[str]];

        int res = 1; // length of chain will be at least of 1
        for (int i = 0; i < len; i++) {
            string next = str;
            next.erase(i, 1);

            // mmake sure the predecessor exists in the given array
            if(word_ht.find(next) != word_ht.end())
                res = max(res, 1 + dfs(words, next));
        }

        memo[word_ht[str]] = res;

        return res;
    }

    int longestStrChain(vector<string>& words) {
        // sort(words.begin(), words.end(),
        //      [](const std::string& first, const std::string& second) {
        //          return first.size() < second.size();
        //      });

        int len = words.size();

        memo.resize(len);

        // fill hash_table
        for (int i = 0; i < len; ++i) {
            word_ht[words[i]] = i;
        }

        // have each word as the starting point
        for (int i = 0; i < len; ++i) {
            dfs(words, words[i]);
        }

        return *max_element(memo.begin(), memo.end());
    }

private:
    unordered_map<string, int> word_ht; // word hash table [string] = index
    vector<int> memo;                   // index, length
};