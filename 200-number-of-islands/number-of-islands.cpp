class Solution {
public:
    bool isOob(int nx, int ny, int m, int n) {
        return nx < 0 || ny < 0 || nx >= m || ny >= n;
    }

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> q;

        q.push({x, y});
        visited[x][y] = true;

        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (!isOob(nx, ny, m, n) && grid[nx][ny] == '1' && !visited[nx][ny]){
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ++ret;
                    bfs(grid, visited, i, j);
                }
            }
        }

        return ret;
    }
};