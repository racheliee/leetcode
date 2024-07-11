class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size();

        vector<pair<int, int>> pairs;
        for(int i = 0; i < j; ++i){
            pairs.push_back({nums[i], i}); // first = nums, second = index
        }

        vector<int> v;
        std::sort(pairs.begin(), pairs.end());

        --j;
        while(i < j){
            if (pairs[i].first + pairs[j].first == target){
                v.push_back(pairs[i].second);
                v.push_back(pairs[j].second);
                break;
            }
            else if(pairs[i].first + pairs[j].first > target){
                --j;
            } else {
                ++i;
            } 
        }

        return v;
    }
};