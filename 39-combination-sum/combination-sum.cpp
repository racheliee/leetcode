class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        getCombination(candidates, 0, target, 0, ret, {});
        return ret;
    }

private:
    void getCombination(vector<int>& candidates, int start, int target, int val, vector<vector<int>>& ret, vector<int> curr){
        if(target == val){
            ret.push_back(curr);
            return;
        }
        if(target < val || start >= candidates.size()){
            return;
        }

    
        curr.push_back(candidates[start]);
        getCombination(candidates, start, target, val + candidates[start], ret, curr);
        curr.pop_back();
        getCombination(candidates, start + 1, target, val, ret, curr);
    }
};