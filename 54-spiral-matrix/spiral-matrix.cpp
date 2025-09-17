class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ret(m * n);

        int l = 0, r = n - 1, t = 0, b = m - 1, idx = 0;
        while (l <= r && t <= b) {
            for (int i = l; i <= r; ++i) // top row
                ret[idx++] = matrix[t][i];
            ++t;

            for (int i = t; i <= b; ++i) // right col
                ret[idx++] = matrix[i][r];
            --r;

            if (t <= b) {
                for (int i = r; i >= l; --i) // bot row
                    ret[idx++] = matrix[b][i];
                --b;
            }

            if (l <= r) {
                for (int i = b; i >= t; --i) // left col
                    ret[idx++] = matrix[i][l];
                ++l;
            }
        }

        return ret;
    }
};