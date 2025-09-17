class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));

        int l = 0, r = n-1, t = 0, b = n-1;
        int a = 1;
        while(l <= r && t <= b) {
            for(int i = l; i <= r; ++i) 
                ret[t][i] = a++;
            t++;

            for(int i = t; i <= b; ++i)
                ret[i][r] = a++;
            --r;

            if(l <= r) {
                for(int i = r; i >= l; --i)
                    ret[b][i] = a++;
                --b;
            }

            if(t <= b) {
                for(int i = b; i >= t; --i)
                    ret[i][l] = a++;
                ++l;
            }
        }


        return ret;
    }
};