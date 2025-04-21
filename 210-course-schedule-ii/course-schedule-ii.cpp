class Solution {
public:
    bool dfs(int curr, vector<int>& ret, vector<int>& visited, const vector<vector<int>>& adj) {
        if (visited[curr] == 2)
            return true; // already visited

        visited[curr] = 1; // visiting
        for (auto i : adj[curr]) {
            if (visited[i] == 1)
                return false; // cycle
            else if (visited[i] == 2)
                continue; // visited

            if (!dfs(i, ret, visited, adj))
                return false;
        }
        visited[curr] = 2; // visited
        ret.push_back(curr);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        int m = prerequisites.size();
        for (int i = 0; i < m; ++i) { // be careful with loop termination
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> ret;
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, ret, visited, adj))
                return {};
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};