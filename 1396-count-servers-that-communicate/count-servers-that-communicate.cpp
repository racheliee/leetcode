class Solution {
public:
    bool isOob(int x, int y, int m, int n){
        return x < 0 || y < 0 || x >= m || y >= n;
    }

    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        int ret = 1;
        q.push({i, j});
        visited[i][j] = true;

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < m; ++i){
                if(visited[i][y] == false && grid[i][y] == 1 && i != x){
                    ++ret;
                    visited[i][y] = true;
                    q.push({i, y});
                }
            }

            for(int j = 0; j < n; ++j){
                if(visited[x][j] == false && grid[x][j] == 1 && j != y){
                    ++ret;
                    visited[x][j] = true;
                    q.push({x, j});
                }
            }
        }

        return ret == 1 ? 0 : ret;
    }

    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int ret = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] && visited[i][j] == false){
                    ret +=  bfs(grid, visited, i, j);
                }
            }
        }

        return ret;
    }
};