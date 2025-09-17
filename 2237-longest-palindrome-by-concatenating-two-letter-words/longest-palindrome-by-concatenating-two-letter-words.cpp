class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        int ret = 0;

        for(const auto& s: words) ++m[s];

        int symcnt = 0;
        for(auto [s, n]: m) {
            if(s[0] == s[1]) {
                symcnt = n % 2 == 1 ?symcnt + 1: symcnt;
                ret += (n / 2) * 2 * 2; // cuz we need on both sides, then len 2 and both sides; order matters 
                continue;
            }

            string reversed = s;
            reverse(reversed.begin(), reversed.end());

            if(m.count(reversed)) 
                ret += min(m[reversed], n) * 2;
        }

        if(symcnt) ret +=2;

        return ret;
    }
};