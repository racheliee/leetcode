class Solution {
public:
    void getCombination(vector<int>& candidates, int start, int len, int target, int val, vector<vector<int>>& ret, vector<int> curr){
        if(target == val){
            ret.push_back(curr);
            return;
        }
        if(target < val){
            return;
        }

    
        for(int i = start; i < len; ++i){
            curr.push_back(candidates[i]);
            getCombination(candidates, i, len, target, val + candidates[i], ret, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        getCombination(candidates, 0, (int)candidates.size(), target, 0, ret, {});
        return ret;
    }
};