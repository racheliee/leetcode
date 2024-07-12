class Solution {
public:
    string reverseWords(string s) {
        string rev = "";

        std::istringstream ss(s);
        std::string word;
        vector<string> v;

        while(ss >> word)
        {
            v.push_back(word);
        }

        reverse(v.begin(), v.end());
        int sz = v.size();

        for(int i = 0; i < sz; ++i){
            rev += v[i];
            if(i != sz-1) rev += " ";
        }
        
        return rev;
    }
};