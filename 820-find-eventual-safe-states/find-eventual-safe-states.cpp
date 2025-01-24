class Solution {
public:
    bool dfs(vector<vector<int>>& graph, map<int, bool> &safe, int i){
        if(safe.find(i) != safe.end()){
            return safe[i];
        }

        safe[i] = false;

        for(auto neighbour: graph[i]){
            if(dfs(graph, safe, neighbour) == false){
                return false;
            }
        }

        safe[i] = true;

        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ret;
        map<int, bool> safe;

        for(int i = 0; i < n; ++i){
            if(dfs(graph, safe, i))
                ret.push_back(i);
        }

        return ret;
    }
};