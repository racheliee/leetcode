class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int len = timePoints.size();
        vector<int> time(len);

        for(int i = 0; i < len; ++i) 
            time[i] = stoi(timePoints[i].substr(0,2)) * 60 + stoi(timePoints[i].substr(3,2));
        
        sort(time.begin(), time.end());

        int ret = INT_MAX;
        for(int i = 0; i < len-1; ++i)
            ret = min(ret, time[i+1] - time[i]);
        
        ret = min(ret, 24*60 - (time[len-1] - time[0]));

        return ret;
    }
};