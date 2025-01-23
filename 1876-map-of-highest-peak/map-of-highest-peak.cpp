class Solution {
public:
    bool isOob(int x, int y, int m, int n) {
        return x < 0 || y < 0 || x >= m || y >= n;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        vector<vector<int>> ret(m, vector<int>(n, -1));

        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j]) {
                    ret[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];

                if (!isOob(nx, ny, m, n) && ret[nx][ny] == -1) {
                    ret[nx][ny] = ret[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return ret;
    }
};