class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;

        while(l < r) {
            int mid = (l+r+1LL)/2; //prevent int overflow

            if(mid > x / mid) // to prevent overflow
                r = mid-1;
            else
                l = mid;
        }

        return r;
    }
};