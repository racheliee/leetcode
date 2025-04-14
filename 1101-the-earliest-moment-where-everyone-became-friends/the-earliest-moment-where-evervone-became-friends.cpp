// leetcode premium—-not sure if this runs
class Solution {
public:
    int find_set(int n) {
        if (n == parent[n])
            return n;
        return parent[n] = find_set(parent[n]); // parent 아래 children 여러개 달기
    }

    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        int len = logs.size();

        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); // fill vector 0, 1, 2, 3, ..., n-1
        int num = n;
        for (auto& log : logs) {
            int f1 = log[1];
            int f2 = log[2];

            int p1 = find_set(f1);
            int p2 = find_set(f2);
            if (p1 != p2) {
                parent[p1] = p2; // union set
                --num;
            }

            if (num == 1)
                return log[0];
        }

        return -1;
    }

private:
    vector<int> parent;
};
