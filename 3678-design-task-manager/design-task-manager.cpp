class TaskManager {
public:
    struct Task {
        int userId;
        int taskId;
        int priority;
        int version;
    };

    struct TaskCompare {
        bool operator()(const Task& a, const Task& b) const {
            return a.priority != b.priority ? (a.priority < b.priority)
                                            : (a.taskId < b.taskId);
        }
    };

    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& v : tasks) {
            int userId = v[0], taskId = v[1], pr = v[2];
            int ver = ++verCounter[taskId];
            pq.push({userId, taskId, pr, ver});
            m[taskId] = {pr, userId, ver};
        }
    }

    void add(int userId, int taskId, int priority) {
        int ver = ++verCounter[taskId];
        pq.push({userId, taskId, priority, ver});
        m[taskId] = {priority, userId, ver};
    }

    void edit(int taskId, int newPriority) {
        auto [oldPr, userId, oldVer] = m[taskId];
        int ver = ++verCounter[taskId];
        pq.push({userId, taskId, newPriority, ver});
        m[taskId] = {newPriority, userId, ver};
    }

    void rmv(int taskId) {
        int ver = ++verCounter[taskId];
        m[taskId] = {-1, -1, ver};
    }

    int execTop() {
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            auto [pr, uid, ver] = m[v.taskId];

            // valid if: not removed, version matches, priority matches
            if (pr != -1 && v.version == ver && v.priority == pr) {
                return v.userId;
            }
        }
        return -1;
    }

private:
    priority_queue<Task, vector<Task>, TaskCompare> pq;
    unordered_map<int, tuple<int, int, int>> m; // taskId, {priority, userId, version}
    unordered_map<int, int> verCounter; // taskId, latest version counter
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */