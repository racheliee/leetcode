class Solution {
public:
    int climb(int num, vector<int>& stairs) {
        if(num == 0)
            return 1;
        if(num < 0) 
            return 0;
        if(stairs[num] != -1)
            return stairs[num];

        stairs[num] = climb(num-1, stairs) + climb(num-2, stairs);
        return stairs[num];
    }

    int climbStairs(int n) {
        vector<int> stairs(n+1, -1);
        stairs[0] = 0;
        return climb(n, stairs);
    }
};