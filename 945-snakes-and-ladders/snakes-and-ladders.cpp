class Solution {
public:

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = (int)board.size();
        int goal = n*n;

        queue<pair<int, int>> q; // position, moves 
        unordered_set<int> visited;
        vector<int> linear_board(n*n +1, -1);

        // 2d를 1d로 펼치기
        bool left_to_right = true;
        int index = 1;
        for(int i = n-1; i >= 0; --i){
            if(left_to_right){
                for(int j = 0; j < n; ++j)
                    linear_board[index++] = board[i][j];
            }else{
                for(int j = n-1; j >= 0; --j){
                    linear_board[index++] = board[i][j];
                }
            }
            left_to_right = !left_to_right; // 방향 바꿔주기
        }

        q.push({1, 0});
        visited.insert(1);

        while(!q.empty()){
            auto [pos, moves] = q.front();
            q.pop();

            for(int i = 1; i <= 6; ++i){
                int new_pos = pos + i;
                
                // ladder인지 아닌지 확인하기
                if(linear_board[new_pos] != -1)
                    new_pos = linear_board[new_pos];

                if(new_pos == goal)
                    return moves+1;
                
                if(visited.find(new_pos) != visited.end())
                    continue;
                
                q.push({new_pos, moves+1});
                visited.insert(new_pos);
            }

        }

        return -1;
    }
};
