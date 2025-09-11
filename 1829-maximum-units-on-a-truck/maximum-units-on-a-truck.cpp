class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });

        int ret = 0, len = boxTypes.size();
        for(int i = 0; i < len; ++i) {
            int num = boxTypes[i][0];
            int unit = boxTypes[i][1];
            while(num) {
                ret += unit;
                --num;
                if(--truckSize == 0)
                    return ret;
            }
        }

        return ret;
    }
};