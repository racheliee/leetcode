class Solution {
public:
    // make sure to pass by reference (&) to use less memory!!
    int editDistance(string& w1, string& w2, int i, int j, vector<vector<int>>& memo){
        if(i == 0) return j;
        if(j == 0) return i;

        if(memo[i][j] != -1) return memo[i][j];

        if(w1[i-1] == w2[j-1])
            memo[i][j] = editDistance(w1, w2, i-1, j-1, memo);
        else    
            memo[i][j] = 1 + min({editDistance(w1, w2, i-1, j-1, memo), editDistance(w1, w2, i-1, j, memo), editDistance(w1, w2, i, j-1, memo)});
        
        return memo[i][j];
    }

    int minDistance(string word1, string word2) {
        int l1 = (int)word1.length();
        int l2 = (int)word2.length();
        vector<vector<int>> memo(l1+1, vector<int> (l2+1, -1));
        return editDistance(word1, word2, l1, l2, memo);
    }
};