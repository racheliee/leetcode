class Solution {
public:
    long long countVowels(string word) {
        int len = word.length();
        string vowels = "aeiou";
        long long ret = 0;

        for(int i = 0; i < len; ++i){
            if(vowels.find(word[i]) != string::npos)
                ret += ((long long)i+1)*(len-i);
        }

        return ret;
    }
};