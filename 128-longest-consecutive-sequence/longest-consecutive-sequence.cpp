class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = (int)nums.size();
        unordered_set<int> s;
        int ret = 0;

        for(int i = 0; i < len; ++i)
            s.insert(nums[i]);
        
        for(int i = 0; i < len; ++i){
            // 지금 element가 sequence의 시작
            if(s.find(nums[i]-1) == s.end()){
                int j = nums[i];
                
                // 계속 j 증가 시키면서 set에 있는지 확인
                while(s.find(j) != s.end())
                    ++j;
                
                ret = max(ret, j - nums[i]);
            }
        }

        return ret;
    }
};