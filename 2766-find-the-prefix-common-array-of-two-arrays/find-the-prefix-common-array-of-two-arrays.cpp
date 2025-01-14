class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = (int)A.size();
        vector<unordered_map<int, int>> v(n);
        
        ++v[0][A[0]];
        ++v[0][B[0]];
        for(int i = 1; i < n; ++i){
            v[i] = v[i-1];
            ++v[i][A[i]];
            ++v[i][B[i]];
        }

        vector<int> ret(n);
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            // cout << "index: " << i << endl;
            for(auto it = v[i].begin(); it != v[i].end(); ++it){
                // cout << "num " << it->first << " occurs " << it->second << endl;
                if(it->second == 2) ++cnt;
            }
            ret[i] = cnt;
            cnt = 0;
        }

        return ret;
    }
};