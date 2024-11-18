class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int len1 = nums1.size();
        int len2 = nums2.size();

        if( k == 0 || len1 == 0 || len2 == 0)
            return res;

        auto cmp = [](const pair<int, pair<int, int>>&a, const pair<int, pair<int, int>> &b){
            return a.first > b.first; // min heap
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> pq(cmp);

        // push initial pairs
        int iter = min(len2, k);
        for(int i = 0; i < iter; ++i){
            pq.push({nums1[0] + nums2[i], {0, i}});
        }

        // extract k smallest pairs
        while(k-- && !pq.empty()){
            auto [sum, indices] = pq.top();
            auto[i, j] = indices;
            pq.pop();

            // add curr pair to the results arr
            res.push_back({nums1[i], nums2[j]});

            // add next pair to heap
            if(i+ 1 < len1){
                pq.push({nums1[i+1]+nums2[j], {i+1, j}});
            }
        }

        return res;
    }
};