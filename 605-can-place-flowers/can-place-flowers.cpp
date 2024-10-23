#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

class Solution {
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int len = flowerbed.size();

        if(len == 0) return false;
        if(n == 0) return true;
        if(len == 1 && flowerbed[0] && n > 1) return false;
        if(len == 1 && !flowerbed[0] && n > 0) return true;

        if (!flowerbed[0] && !flowerbed[1]) {
            --n;
            flowerbed[0] = 1;
            // cout << n << endl;
        }

        for (int i = 1; i < len - 1; ++i) {
                cout << "i: " << i << endl;
            if (flowerbed[i])
                continue;
            else if (!flowerbed[i + 1] && !flowerbed[i - 1]) {
                flowerbed[i] = 1;
                --n;
                // cout << n << endl;
                i += 1;
            }
            if (n == 0)
                break;
        }

        if(!flowerbed[len-1] && !flowerbed[len-2])
            n--;

        // cout << n << endl;

        return n <= 0;
    }
};
