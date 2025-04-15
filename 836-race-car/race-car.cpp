class Solution {
public:
    int racecar(int target) {
        queue<pair<pair<long long, long long>, int>> q; // pos, speed, moves
        q.push({{0, 1}, 0});

        set<pair<long long, long long>> visited;

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();

            if (curr.first == target)
                return moves;

            if (visited.find(curr) != visited.end())
                continue;
            visited.insert(curr);

            long long pos = curr.first, speed = curr.second;

            // case: 'A'
            q.push({{pos + speed, speed * 2}, moves + 1});

            // case: 'R'
            // only needed when we're below target and speed is negative
            // and when we're above target and speed is positive
            if ((pos + speed < target && speed < 0) ||
                (pos + speed > target && speed > 0)) {
                q.push({{pos, speed < 0 ? 1 : -1}, moves + 1});
            }
        }

        return -1;
    }
};