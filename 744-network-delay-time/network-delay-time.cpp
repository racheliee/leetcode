class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        int len = times.size();
        for (int i = 0; i < len; ++i)
            adj[times[i][0]].push_back({times[i][1], times[i][2]});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            pq; // dist, node; min heap
        vector<int> dist(n + 1, INT_MAX);

        pq.push({0, k});
        dist[k] = 0;

        while (!pq.empty()) {
            auto [d, n] = pq.top();
            pq.pop();

            for (auto [nx, nd] : adj[n]) {
                if (dist[nx] > dist[n] + nd) {
                    dist[nx] = dist[n] + nd;
                    pq.push({dist[nx], nx});
                }
            }
        }

        int ret = *max_element(dist.begin()+1, dist.end()); // skip first index since 1-indexed
        return ret == INT_MAX ? -1 : ret;
    }
};