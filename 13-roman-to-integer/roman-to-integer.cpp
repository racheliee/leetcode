class Solution {
public:
    int values(char c) {
        switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;

        case 'X':
            return 10;

        case 'L':
            return 50;

        case 'C':
            return 100;

        case 'D':
            return 500;

        case 'M':
            return 1000;
        }
        return -1;
    }
    int romanToInt(string s) {
        int ret = 0, len = s.length() - 1;

        for (int i = 0; i < len; ++i) {
            if(values(s[i]) < values(s[i+1]))
                ret -= values(s[i]);
            else
                ret += values(s[i]);
        }

        ret += values(s[len]);

        return ret;
    }
};