class Solution {
public:
    bool dfs(int course, vector<vector<int>>& adj, vector<int>& visited){
        if(visited[course] == 2) return true;
        if(visited[course] == 1) return false;
        
        visited[course] = 1;
        for(auto &p: adj[course]) {
            if(!dfs(p, adj, visited))
                return false;
        }

        visited[course] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(const auto& p: prerequisites)
            adj[p[1]].push_back(p[0]);
        
        vector<int> visited(numCourses, 0);
        for(int i = 0; i < numCourses; ++i) {
            if(!dfs(i, adj, visited))
                return false;
        }

        return true;
    }
};