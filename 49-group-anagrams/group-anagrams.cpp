class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = (int)strs.size();
        vector<vector<string>> ret;
        
        if(len == 0)
            return ret;
        
        map<map<char, int>, vector<string>> m;

        for(auto word: strs){
            map<char, int> tmp;
            for(auto c: word)
                ++tmp[c];
            
            m[tmp].push_back(word);
        }

        for(auto it = m.begin(); it != m.end(); ++it){
            ret.push_back(it->second);
        }

        return ret;
    }
};