class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (i == 0) grid[i][j] += grid[i][j-1];
                else if (j == 0) grid[i][j] += grid[i-1][j];
                else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }

        return grid[m-1][n-1];
    }
};


/* dfs solution
class Solution {
public:    
    bool is_oob(int x, int y, int m, int n) {
        if(x < 0 || x >= m || y < 0 || y >= n)
            return true;
        return false;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq; // sum, <x, y>
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        while(!pq.empty()) {
            auto [sum, coor] = pq.top();
            pq.pop();

            if(coor.first == m -1 && coor.second == n - 1) return sum;
            if(dist[coor.first][coor.second] < sum) continue;

            for(int i = 0; i < 2; ++i) {
                int x = coor.first + dx[i], y = coor.second + dy[i];
                if(is_oob(x, y, m, n)) continue;
                
                int newSum = sum + grid[x][y];
                if(newSum < dist[x][y]){
                    pq.push({newSum, {x, y}});
                    dist[x][y] = newSum;
                }
            }
        }

        return -1;
    }

private:
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};
};
*/