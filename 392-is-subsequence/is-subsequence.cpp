class Solution {
public:
    bool isSubsequence(string s, string t) {
        if ((int)s.length() > (int)t.length()) return false;

        size_t idx = 0;
        for(char c: s){
            size_t found = t.find(c, idx);
            if(found == string::npos)
                return false;

            idx = found + 1;
        }
        return true;
    }
};