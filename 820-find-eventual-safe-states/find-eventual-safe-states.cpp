class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &safe, int i){
        if(safe[i] != 0){
            return safe[i] == 2;
        }

        safe[i] = 1;

        for(auto neighbour: graph[i]){
            if(dfs(graph, safe, neighbour) == false){
                return false;
            }
        }

        safe[i] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ret;
        vector<int> safe(n, 0);

        for(int i = 0; i < n; ++i){
            if(dfs(graph, safe, i))
                ret.push_back(i);
        }

        return ret;
    }
};