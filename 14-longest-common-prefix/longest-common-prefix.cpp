class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";

        int len = strs[0].length();
        string ret = "";

        for(int i = 0; i < len; ++i) {
            for(auto& s: strs) {
                if(s.length() <= i || s[i] != strs[0][i])
                    return ret;
            }
            ret += strs[0][i];    
        }

        return ret;
    }
};