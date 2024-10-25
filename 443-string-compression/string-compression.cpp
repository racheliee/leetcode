#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int len = (int)chars.size();

        int i = 0;
        int curr = 0;
        int count = 0;
        stack<int> s;
        while(i < len){
            while(curr < len && chars[i] == chars[curr]){
                ++curr;
                ++count;
            }
            chars.push_back(chars[i]);
            i = curr;
            if (count == 1) {
                count = 0;
                continue;
            }

            string s = to_string(count);
            for(auto c: s){
                chars.push_back(c);
            }
            
            count = 0;
        }

        chars.erase(chars.begin(), chars.begin() + len);

        return (int)chars.size();
    }
};
