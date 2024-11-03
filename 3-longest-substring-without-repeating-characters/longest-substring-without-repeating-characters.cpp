class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0, start = 0, len = (int)s.length();
        unordered_map<char, int> tracker;

        char c;
        for(int end = 0; end < len; ++end){
            c = s[end];
            if(tracker.find(c) != tracker.end() && tracker[c] >= start){
                start = tracker[c] + 1;
            }

            tracker[c] = end;

            max = max < (end-start+1) ? (end-start+1) : max;
        }
        return max;
    }
};