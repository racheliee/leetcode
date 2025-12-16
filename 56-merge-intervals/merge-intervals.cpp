class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] < b[1];
                 return a[0] < b[0];
             });
        vector<vector<int>> ret;

        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            } else {
                ret.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ret.push_back({start, end});

        return ret;
    }
};