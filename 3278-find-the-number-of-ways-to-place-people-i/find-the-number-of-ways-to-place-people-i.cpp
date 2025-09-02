class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int m = points.size(), ret = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == j)
                    continue;
                int x1 = points[i][0], x2 = points[j][0];
                int y1 = points[i][1], y2 = points[j][1];

                if (x1 > x2 || y1 < y2)
                    continue;

                bool flag = true;
                for (int k = 0; k < m; ++k) {
                    int mx = points[k][0], my = points[k][1];
                    if (mx == x1 && my == y1)
                        continue;
                    if (mx == x2 && my == y2)
                        continue;

                    if (x1 <= mx && mx <= x2 && y2 <= my && my <= y1) {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                    ++ret;
            }
        }
        return ret;
    }
};