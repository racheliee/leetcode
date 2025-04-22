class DetectSquares {
public:
    DetectSquares() : coor() {}

    void add(vector<int> point) { ++coor[point[0]][point[1]]; }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int ret = 0;

        for (auto& [x2, y_coor] : coor) {
            if (x2 == x)
                continue;

            int d = abs(x2 - x);

            ret += y_coor[y] * y_coor[y + d] * coor[x][y + d];
            ret += y_coor[y] * y_coor[y - d] * coor[x][y - d];
        }

        return ret;
    }

private:
    unordered_map<int, unordered_map<int, int>> coor;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */