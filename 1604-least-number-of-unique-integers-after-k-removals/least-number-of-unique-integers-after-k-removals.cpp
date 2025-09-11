class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int len = arr.size();
        if(k == len) return 0;

        unordered_map<int, int> m;
        priority_queue<int, vector<int>, greater<>> pq;

        for(int i = 0; i < len; ++i)
            ++m[arr[i]];

        int num_unique = m.size();        
        for(const auto& e: m)
            pq.push(e.second);
        
        while(!pq.empty() && k) {
            k -= pq.top();
            pq.pop();
            if(k < 0) return num_unique;
            --num_unique;
            if(k == 0) return num_unique;
        }

        return num_unique;
    }
};