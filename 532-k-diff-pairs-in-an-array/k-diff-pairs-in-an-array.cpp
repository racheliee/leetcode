class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(const auto& n: nums) ++m[n];
        unordered_map<int, unordered_set<int>> visited;

        int ret = 0;
        for(const int& n: nums) {
            if(m.count(n+k) && visited[n].find(n+k) == visited[n].end()){
                if(n == n+k && m[n] < 2) continue; 
                visited[n].insert(n+k);
                visited[n+k].insert(n);
                cout << n << " " << n+k << endl;
                ++ret;
            }
        }
        return ret;
    }
};