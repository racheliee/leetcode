class MyCalendar {
public:
    MyCalendar() : bookings() {}

    bool book(int startTime, int endTime) {
        // get the booking with the start_time of at least startTime
        auto curr = bookings.lower_bound(startTime);

        if (curr != bookings.end()) {
            cout << curr->first << " " << curr->second << endl;
        }

        // check if there is a conflict with the startTime of curr (make sure
        // it's not the end)
        if (curr != bookings.end() && curr->first < endTime)
            return false;

        // check if the startTime doesn't have conflict with the endTime of the prvious of curr
        if (curr != bookings.begin() && prev(curr)->second > startTime)
            return false;

        bookings[startTime] = endTime; // don't forget to add it!!

        return true;
    }

private:
    map<int, int> bookings;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */