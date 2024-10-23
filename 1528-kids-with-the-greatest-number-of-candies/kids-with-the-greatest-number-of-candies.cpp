#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

class Solution {
  public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        int max = *max_element(candies.begin(), candies.end());
        int len = (int)candies.size();
        vector<bool> ret(len);

        for(int i = 0; i < len; ++i){
            ret[i] = (extraCandies + candies[i]) >= max ? true : false;
        }

        return ret;
    }
};