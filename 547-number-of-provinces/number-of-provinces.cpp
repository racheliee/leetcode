class Solution {
public:
    void bfs(int node, vector<int>& visited, vector<vector<int>>& isConnected) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        int n = isConnected.size();

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int i = 0; i < n; ++i) {
                if (isConnected[curr][i] == 1 && visited[i] == 0) {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ret = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                bfs(i, visited, isConnected);
                ++ret;
            }
        }

        return ret;
    }
};