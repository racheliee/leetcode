class Solution {
public:
    bool is_oob(int x, int y, int m, int n) {
        return x < 0 || y < 0 || x >= m || y >= n;
    }

    void bfs(vector<vector<char>> & grid, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        q.push({row, col});

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if(is_oob (nx, ny, m, n))
                    continue;
                
                if(grid[nx][ny] == '1') { // this is a char grid
                    q.push({nx, ny});
                    grid[nx][ny] = '0';
                }
            }
        }

    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int ret = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    bfs(grid, i, j);
                    ++ret;
                }
            }
        }

        return ret;
    }

private:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
};