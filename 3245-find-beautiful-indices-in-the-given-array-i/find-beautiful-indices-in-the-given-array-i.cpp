class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ret;
        int len = s.length();
        int alen = a.length();
        int blen = b.length();

        int idx = 0;
        while (true) {
            int finda = s.find(a, idx);
            if (finda == string::npos) break;

            int left = max(0, finda - k);
            int right = min(len - blen, finda + k);

            int findb = s.find(b, left);
            if (findb != string::npos && findb <= right)
                ret.push_back(finda);
            

            idx = finda + 1;
        }

        return ret;
    }
};