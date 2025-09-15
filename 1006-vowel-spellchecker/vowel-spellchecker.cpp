class Solution {
public:
    string maskVowels(string a) {
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};
        int end = a.length();
        for (int i = 0; i < end; ++i)
            if (v.find(a[i]) != v.end())
                a[i] = '*';
        return a;
    }

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};
        // unordered_map<string, string> m;
        int len = (int)queries.size();
        vector<string> ret(len);

        // its better to have three maps because we dont get confused with entries
        unordered_map<string, string> exact;   // exact words
        unordered_map<string, string> lower;   // lowercase form
        unordered_map<string, string> masked;  // vowel-masked form

        for (auto &w : wordlist) {
            exact[w] = w;

            string l = w;
            transform(l.begin(), l.end(), l.begin(), ::tolower);
            if (!lower.count(l)) lower[l] = w;

            string m = maskVowels(l);
            if (!masked.count(m)) masked[m] = w;
        }

        
        // can't reverse iterate because kite matches with KiTe not kite
        // for (auto it = wordlist.rbegin(); it != wordlist.rend(); ++it) {
        //     string s = *it;
        //     m[s] = s;
        //     string l = s;
        //     transform(l.begin(), l.end(), l.begin(), ::tolower);
        //     m[l] = s;
        //     m[maskVowels(l)] = s;
        // }

        for (int i = 0; i < len; ++i) {
            string curr = queries[i];
            if (exact.count(curr)) { // exact
                ret[i] = exact[curr];
                continue;
            }

            string l = curr;
            transform(l.begin(), l.end(), l.begin(), ::tolower);
            if (lower.count(l)) { // case insensitive
                ret[i] = lower[l];
                continue;
            }

            string m = maskVowels(l);
            if (masked.count(m)) { // masked vowel
                ret[i] = masked[m];
                continue;
            }

            ret[i] = "";
        }

        return ret;
    }
};