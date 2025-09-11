class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0, bob = 0;

        int idx = 0, len = colors.length();
        while(idx < len) {
            char curr = colors[idx];
            int cnt = 0;
            while(idx < len && curr == colors[idx]) {
                ++idx;
                ++cnt;
            }
            if(curr == 'A') alice += max(cnt-2, 0);
            if(curr == 'B') bob += max(cnt-2, 0);
        }
        
        return (alice > bob && alice != 0) ? true : false;
    }
};