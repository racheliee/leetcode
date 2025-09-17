class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ret = 0;

        for(const auto& n: s) { //iterate the set, not the nums
            // if there is an early start, skip
            if(s.find(n-1) != s.end()) continue;

            int find = n;
 
            while(s.find(find) != s.end())
                ++find;
            
            ret = max(ret, find - n);
        }   

        return ret;
    }
};