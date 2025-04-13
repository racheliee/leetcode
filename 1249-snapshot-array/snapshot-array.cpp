
class SnapshotArray {
public:
    SnapshotArray(int length) {
        snap_id = 0;
        snaps.clear();
        snaps.resize(length);
    }
    
    void set(int index, int val) {
        snaps[index][snap_id] = val; // O(log(snap calls))
    }
    
    int snap() {
        ++snap_id;
        return snap_id - 1; // O(1)
    }
    
    int get(int index, int snap_id) { // O(log(snap calls))
        auto &m = snaps[index];
        auto it = m.upper_bound(snap_id);
        if (it == m.begin()) return 0;
        return (--it)->second;
    }

private:
    vector<map<int, int>> snaps; // snaps[index] = snap_id, val; space: O(indices*snap()))
    int snap_id;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */