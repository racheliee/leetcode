class Solution {
public:
    bool isOob(int r, int c, int m, int n){
        return r < 0 || c < 0 || m <= r || n <= c;
    }

    int bfs(vector<vector<int>>& grid, int r, int c){
        int m = grid.size(), n = grid[0].size();
        int fish = grid[r][c]; //remember u have to include the curr fish num!!
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};

        visited[r][c] = true;
        q.push({r, c});
        
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; ++i){
                int nx = x + dx[i], ny = y + dy[i];

                if(isOob(nx, ny, m, n) || visited[nx][ny])
                    continue;
                visited[nx][ny] = true;
                if(grid[nx][ny] != 0){
                   fish += grid[nx][ny];
                   q.push({nx, ny});
                }
            }
        }

        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ret = 0;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 0)
                    continue;
                
                ret  = max(ret, bfs(grid, i, j));
            }
        }

        return ret;
    }
};