class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> v;
        unordered_map<char, int> c;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for(const char& a: s) {
            if(vowels.find(a) != vowels.end()) ++v[a];
            else ++c[a];
        }

        int vmax = 0;
        for(auto it = v.begin(); it != v.end(); ++it)
            vmax = max(vmax, it->second);

        int cmax = 0;
        for(auto it = c.begin(); it != c.end(); ++it)
            cmax = max(cmax, it->second);

        return cmax + vmax;
    }
};