class Solution {
public:
    bool union_set(vector<int>& parent, vector<int>& rank, int a, int b) {
        int pa = find(parent, a);
        int pb = find(parent, b);

        if (pa == pb)
            return false;
        if (rank[pa] > rank[pb]) {
            parent[pb] = pa;
            rank[pa] += rank[pb];
        } else {
            parent[pa] = pb;
            rank[pb] += rank[pa];
        }

        return true;
    }

    int find(vector<int>& parent, int node) {
        int p = parent[node];

        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }

        return p;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 1);

        for (int i = 0; i < n + 1; ++i)
            parent[i] = i;

        for (int i = 0; i < n; ++i) {
            if (!union_set(parent, rank, edges[i][0], edges[i][1]))
                return vector<int>{edges[i][0], edges[i][1]};
        }

        return {};
    }
};