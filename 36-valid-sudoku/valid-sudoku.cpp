class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> rows(9);
        vector<vector<unordered_set<char>>> squares(3, vector<unordered_set<char>>(3));

        char cell;
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                cell = board[i][j];
                if(cell !='.'){
                    if(rows[i].find(cell) != rows[i].end() || squares[i/3][j/3].find(cell) != squares[i/3][j/3].end())
                        return false;
                    else{
                        squares[i/3][j/3].insert(cell);
                        rows[i].insert(cell);
                    }
                }
            }
        }

        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                cell = board[j][i];
                if(cell != '.'){
                    if(cols[i].find(cell) != cols[i].end())
                        return false;
                    else
                        cols[i].insert(cell);
                }
            }
        }

        return true;
    }
};