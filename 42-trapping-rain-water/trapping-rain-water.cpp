class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> right(len);
        vector<int> left(len);

        right[0] = height[0];
        for(int i = 1; i < len; ++i) 
            right[i] = max(right[i-1], height[i]);


        left[len-1] = height[len-1];
        for(int i = len - 2; i > -1; --i)
            left[i] = max(left[i+1], height[i]);

        int water = 0;
        for(int i = 0; i < len; ++i)
            water += min(left[i], right[i]) - height[i];

        return water;
    }
};