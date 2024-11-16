class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j  = (int)numbers.size() -1;

        int curr;
        while(i <= j){
            curr = numbers[i] + numbers[j];

            if(curr == target){
                vector<int> v = {i+1, j+1};
                return v;
            }

            if(curr < target){
                ++i;
            }else{
                --j;
            }
        }

        return vector<int> ();
    }
};