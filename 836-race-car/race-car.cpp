
class Solution {
  public:
    typedef struct race_car {
        long long pos;
        long long speed;
        int moves;

        bool operator==(const race_car& other) const {
            return pos == other.pos && speed == other.speed;
        }
    };

    struct race_car_hash {
        size_t operator()(const race_car& rc) const {
            return hash<int>()(rc.pos) ^ (hash<int>()(rc.speed) << 1);
        }
    };

    int racecar(int target) {
        queue<race_car> q;

        q.push({0, 1, 0});

        unordered_set<race_car, race_car_hash> visited;

        while (!q.empty()) {
            race_car curr = q.front();
            q.pop();

            if(curr.pos == target)
                return curr.moves;
            
            if(visited.find(curr) != visited.end())
                continue;

            visited.insert(curr);
            
            q.push({curr.pos + curr.speed, curr.speed * 2, curr.moves + 1});

            if((curr.pos + curr.speed > target && curr.speed > 0) || (curr.pos + curr.speed < target && curr.speed < 0)){
                q.push({curr.pos, curr.speed < 0 ? 1 : -1, curr.moves + 1});
            }
        }

        return -1;
    }
};