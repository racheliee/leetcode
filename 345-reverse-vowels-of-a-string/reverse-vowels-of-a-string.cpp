class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowels;
        unordered_set<char> vset({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        deque<int> idx;

        int len = (int)s.length();
        for(int i = len-1; i >=0; --i){
            if(vset.find(s[i]) != vset.end()){
                idx.push_front(i);
                vowels.push_back(s[i]);
            }
        }

        int len2 = (int)idx.size();
        for(int i = 0, c = 0; i < len && c < len2; ++i){ // c is the index for the vowel sets
            if(i == idx[c]){
                s[i] = vowels[c];
                c++;
            }
        }    

        return s;
    }
};