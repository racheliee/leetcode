class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = (int) intervals.size();
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end());

        ret.push_back(intervals[0]);

        for(int i = 1; i < len; ++i){
            auto last = ret.back();
            auto curr = intervals[i];

            if(last[1] >= curr[0]){ // merge interval
                ret.back()[1] = max(last[1], curr[1]);
            }else {
                ret.push_back(curr);
            }
        }

        return ret;
    }
};