class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        visited.insert(n);

        while(n != 1) {
            int happy = 0;
            while(n > 0) {
                happy += pow((n%10), 2); 
                n /= 10;
            }
            if(visited.find(happy) != visited.end())
                return false;
            visited.insert(happy);
            n = happy;
        }

        return true;
    }
};