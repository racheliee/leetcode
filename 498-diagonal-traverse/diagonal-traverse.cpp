class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int curr = 0;
        int m = mat.size(), n = mat[0].size();
        vector<int> ret;
        ret.reserve(m*n);

        for (int curr = 0; curr < m + n - 1; ++curr) {
            if (curr % 2 == 0) {
                int r = min(curr, m - 1);
                int c = curr - r;
                while (r >= 0 && c < n) {
                    ret.push_back(mat[r][c]);
                    --r; ++c;
                }
            } else {
                int c = min(curr, n - 1);
                int r = curr - c;
                while (r < m && c >= 0) {
                    ret.push_back(mat[r][c]);
                    ++r; --c;
                }
            }
        }

        return ret;
    }
};