#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

class Solution {
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int len = flowerbed.size();

        if(n == 0) return true;

        if(len < 2){
            if(flowerbed[0]) return false;
            else if(n > 1) return false;
            else return true;
        }

        if (!flowerbed[0] && !flowerbed[1]) {
            --n;
            flowerbed[0] = 1;
        }

        for (int i = 2; i < len - 1; ++i) {
            if (flowerbed[i])
                continue;
            else if (!flowerbed[i + 1] && !flowerbed[i - 1]) {
                flowerbed[i] = 1;
                --n;
                i += 1;
            }
            if (n == 0)
                break;
        }

        if (!flowerbed[len - 1] && !flowerbed[len - 2])
            n--;

        return n <= 0;
    }
};