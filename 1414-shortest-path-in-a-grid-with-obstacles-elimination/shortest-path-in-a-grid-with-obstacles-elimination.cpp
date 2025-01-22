class Solution {
public:
    int isOob(int x, int y, int m, int n) {
        return x < 0 || y < 0 || x >= m || y >= n;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));

        priority_queue<pair<int, pair<pair<int, int>, int>>, vector<pair<int, pair<pair<int, int>, int>>>, greater<>> pq; // moves, <pos(x, y), k>

        pq.push({0, {{0, 0}, k}});
        visited[0][0][k] = true;

        while (!pq.empty()) {
            auto [moves, curr] = pq.top();
            auto [x, y] = curr.first;
            int ck = curr.second;
            pq.pop();

            if (x == m - 1 && y == n - 1)
                return moves;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];

                if (isOob(nx, ny, m, n))
                    continue;

                if (grid[nx][ny] && ck > 0 && !visited[nx][ny][ck-1]) {
                    pq.push({moves + 1, {{nx, ny}, ck - 1}});
                    visited[nx][ny][ck - 1] = true;
                } else if (grid[nx][ny] == 0 && !visited[nx][ny][ck]) {
                    pq.push({moves + 1, {{nx, ny}, ck}});
                    visited[nx][ny][ck] = true;
                }
            }
        }

        return -1;
    }
};