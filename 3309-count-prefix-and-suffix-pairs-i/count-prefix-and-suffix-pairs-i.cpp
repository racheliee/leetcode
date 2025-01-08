class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int len = int(words.size());
        int ret = 0;

        int prefsuff;
        for(int i = 0; i < len; ++i){
            for(int j = i+1; j < len; ++j){
                prefsuff = words[i].length();

                if(prefsuff > words[j].length())
                    continue;
                
                if(words[i] == words[j].substr(0, prefsuff)){
                    if(words[i] == words[j].substr(words[j].length()-prefsuff)){
                        ++ret;
                    }
                }
            }
        }

        return ret;
    }
};