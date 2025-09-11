class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string, int>> r = {
            {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100},
            {"XC", 90},  {"L", 50},   {"XL", 40}, {"X", 10},   {"IX", 9},
            {"V", 5},    {"IV", 4},   {"I", 1}};

        string ret = "";
        for (const auto& [sym, n] : r) {
            int q = num / n;
            if (!q) continue;
            while (q--) ret += sym;
            num %= n;
        }

        return ret;
    }
};