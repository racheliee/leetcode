
class Router {
public:
    struct Packet {
        int src;
        int dest;
        int timestamp;
    };

    struct PairHash {
        size_t operator()(const pair<int, int>& p) const noexcept {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    Router(int memoryLimit) : limit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        if (m.count(timestamp) &&
            m[timestamp].find({source, destination}) != m[timestamp].end())
            return false;

        dq.push_back({source, destination, timestamp});
        m[timestamp].insert({source, destination});
        destTimestamps[destination].push_back(timestamp);
        if (dq.size() > limit) {
            Packet p = dq.front();
            dq.pop_front();
            m[p.timestamp].erase({p.src, p.dest});
            if (m[p.timestamp].empty())
                m.erase(p.timestamp);

            auto& vec = destTimestamps[p.dest];
            vec.erase(vec.begin());
            if (vec.empty())
                destTimestamps.erase(p.dest);
        }
        return true;
    }

    vector<int> forwardPacket() {
        if (dq.empty())
            return {};
        Packet p = dq.front();
        dq.pop_front();

        m[p.timestamp].erase({p.src, p.dest});
        if (m[p.timestamp].empty())
            m.erase(p.timestamp);

        auto& vec = destTimestamps[p.dest];
        if (!vec.empty() && vec.front() == p.timestamp) {
            vec.erase(vec.begin());
            if (vec.empty())
                destTimestamps.erase(p.dest);
        }

        return {p.src, p.dest, p.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!destTimestamps.count(destination))
            return 0;
        auto& vec = destTimestamps[destination];

        auto it1 = lower_bound(vec.begin(), vec.end(), startTime);
        auto it2 = upper_bound(vec.begin(), vec.end(), endTime);
        return it2 - it1;
    }

private:
    int limit;
    unordered_map<int, unordered_set<pair<int, int>, PairHash>> m;
    deque<Packet> dq;
    unordered_map<int, vector<int>> destTimestamps;
};