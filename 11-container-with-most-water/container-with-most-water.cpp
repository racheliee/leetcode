class Solution {
public:
    int maxArea(vector<int>& height) {
        int t1 = 0;
        int t2 = (int)height.size()-1;

        int curr, max = -1;
        int h1, h2;
        while(t1 < t2){
            h1 = height[t1];
            h2 = height[t2];
            curr = (t2-t1) * min(h1, h2);

            if(curr > max)
                max = curr;

            if(h1 <= h2)
                ++t1;
            else
                --t2;
        }

        return max;
    }
};