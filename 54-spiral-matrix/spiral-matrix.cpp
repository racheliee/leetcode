class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();

        int top = 0, bot = m-1, left = 0, right = n-1, idx = 0;
        vector<int> ret(m*n);
        while(top <= bot && left <= right){
            for(int i = left; i <= right; ++i)
                ret[idx++] = matrix[top][i];
            ++top;

            for(int i = top; i <= bot; ++i)
                ret[idx++] = matrix[i][right];
            --right;
            
            if(top <= bot){
                for(int i = right; i >=left; --i)
                    ret[idx++] = matrix[bot][i];
                --bot;
            }

            if(left <= right){
                for(int i = bot; i >= top; --i){
                    ret[idx++] = matrix[i][left];
                }
                ++left;
            }
        }

        return ret;
    }
};