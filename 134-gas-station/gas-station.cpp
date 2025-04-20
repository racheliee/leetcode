class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // if total is negative, we cannot go around no matter what
        int fuel = accumulate(gas.begin(), gas.end(), 0) - accumulate(cost.begin(), cost.end(), 0);

        if(fuel < 0)
            return -1;

        int n = (int)gas.size();
        int start = 0, curr = 0; // starting gas station, current gas price

        for(int i = 0; i < n && start < n; ++i) {
            curr += gas[i] - cost[i];

            if(curr < 0) { // if curr is negative, start can't be a starting point
                start = i + 1; // start doesn't work at station i
                curr = 0;
            }
        }

        return start;
    }
};