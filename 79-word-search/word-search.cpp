class Solution {
public:
    bool is_oob(int x, int y, int m, int n) {
        if(x < 0 || x >= m || y < 0 || y >= n) return true;
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int idx, int x, int y) {
        if(idx == word.length()) return true;
        if(is_oob(x, y, board.size(), board[0].size())) return false;
        if(board[x][y] != word[idx]) return false;

        char temp = board[x][y];
        board[x][y] = '*';

        bool search = false;
        for(int i = 0; i < 4; ++i) {
            if(dfs(board, word, idx + 1, x + dx[i], y + dy[i])){
                search = true;
                break;
            }
        }

        board[x][y] = temp;

        return search;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) 
                if(board[i][j] == word[0])
                    if(dfs(board, word, 0, i, j)) return true;

        return false;
    }

private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
};

/** bfs doesn't really work well here. visited needs to be a 3d array to avoid early pruning
    bool is_oob(int x, int y, int m, int n) {
        if(x < 0 || x >= m || y < 0 || y >= n)
            return true;
        return false;
    }

    bool bfs(vector<vector<char>>& board, string word, int start_x, int start_y) {
        int m = board.size(), n = board[0].size();
        int len = word.length();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q; // <<x, y>, idx>
        
        q.push({{start_x, start_y}, 0});
        visited[start_x][start_y] = 1;

        while(!q.empty()) {
            auto [coor, idx] = q.front();
            visited[coor.first][coor.second] = 1;
            q.pop();

            for(int i = 0; i < 4; ++i) {
                int x = coor.first + dx[i], y = coor.second + dy[i];
                if(is_oob(x, y, m, n))
                    continue;
                if(visited[x][y])
                    continue;
                if(word[idx+1] == board[x][y]) {
                    if(idx + 1 == len - 1)
                        return true;
                    q.push({{x, y}, idx + 1});
                }
            }
        }

        return false;
    }
*/