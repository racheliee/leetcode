class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int i = 0, j = 0;
        int len1 = word1.length();
        int len2 = word2.length();

        string merge = "";

        while (i < len1 && j < len2) {
            merge += word1[i++];
            merge += word2[j++];
        }

        while (i < len1) {
            merge += word1[i++];
        }

        while (j < len2) {
            merge += word2[j++];
        }

        return merge;
    }
};