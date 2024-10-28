#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int slen = (int)spells.size();
        int plen = (int)potions.size();
        vector<int> ret(slen, 0);

        long long required_potion;
        for(int i = 0; i < slen; ++i){
            required_potion = ceil((double)success/spells[i]);
            ret[i] = potions.end() - lower_bound(potions.begin(), potions.end(), required_potion);
        }

        return ret;
    }
};