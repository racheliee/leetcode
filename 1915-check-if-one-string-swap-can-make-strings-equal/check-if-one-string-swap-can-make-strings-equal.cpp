class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2)
            return true;

        int len1 = (int)s1.length();
        int len2 = (int)s2.length();

        for(int i = 0; i < len1-1; ++i){
            for(int j = i+1; j < len1; ++j){
                swap(s1[i], s1[j]);
                if(s1 == s2)
                    return true;
                swap(s1[i], s1[j]);
            }
        }

        return false;
    }
};