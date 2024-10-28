class Solution {
public:
    int maxVowels(string s, int k) {
        int len = (int)s.length();
        set<char> vs({'a', 'e', 'i', 'o', 'u'});
        vector<bool> history(len, false);

        int v = 0;
        int i = 0;
        for(; i < k; ++i){
            if(vs.find(s[i]) != vs.end()){
                ++v;
                history[i] = true;
            }
        }

        if(len == k)
            return v;

        int max = v;
        for(int i = k; i < len; ++i){
            if(vs.find(s[i]) != vs.end()){
                history[i] = true;
                ++v;
            }
            if(history[i-k])
                --v;

            max = max < v ? v : max;
        }   

        return max;
    }
};