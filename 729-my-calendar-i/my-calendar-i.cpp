class MyCalendar {
public:
    MyCalendar() { root = nullptr; }

    struct booking {
        int start;
        int end;
        booking* right;
        booking* left;
    };

    bool add_booking(int start, int end) {
        booking* curr = root;

        while (1) {
            if (end <= curr->start) {
                if (!curr->left) {
                    curr->left = new booking{start, end, nullptr, nullptr};
                    return true;
                }
                curr = curr->left;
            } else if (start >= curr->end) {
                if (!curr->right) {
                    curr->right = new booking{start, end, nullptr, nullptr};
                    return true;
                }
                curr = curr->right;
            } else {
                return false;
            }
        }
    }

    bool book(int startTime, int endTime) {
        if (!root) {
            root = new booking{startTime, endTime, nullptr, nullptr};
            return true;
        }

        return add_booking(startTime, endTime);
    }

private:
    booking* root;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */