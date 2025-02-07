class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colours;
        unordered_map<int, int> balls;
        vector<int> ret;
        int n = queries.size();

        for (int i = 0; i < n; ++i) {
            int b = queries[i][0]; // ball
            int c = queries[i][1]; // colour

            ++colours[c];

            if (balls.contains(b) && --colours[balls[b]] == 0)
                colours.erase(balls[b]);

            balls[b] = c;
            ret.push_back(colours.size());
        }

        return ret;
    }
};