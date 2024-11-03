class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = (int)strs.size();
        vector<vector<string>> ret;
        
        if(len == 0)
            return ret;
        
        unordered_map<string, vector<string>> m;

        for(auto word: strs){
            string temp = word;
            sort(temp.begin(), temp.end());
            m[temp].push_back(word);
        }

        for(auto it = m.begin(); it != m.end(); ++it){
            ret.push_back(it->second);
        }

        return ret;
    }
};