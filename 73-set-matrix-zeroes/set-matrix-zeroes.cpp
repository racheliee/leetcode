class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool row0 = false, col0 = false;

        // check col 0
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                col0 = true;
                break;
            }
        }

        // check row 0
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                row0 = true;
                break;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }

        // skip the first row/col
        for (int i = 1; i < m; ++i)
            if (matrix[i][0] == 0)
                matrix[i] = vector<int>(n, 0);

        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0)
                for (int i = 1; i < m; ++i)
                    matrix[i][j] = 0;
        }

        // then come back to the first row/col
        if (row0)
            matrix[0] = vector<int>(n, 0);

        if (col0)
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
    }
};