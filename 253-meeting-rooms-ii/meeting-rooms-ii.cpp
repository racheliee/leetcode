// solved on neetcode: https://neetcode.io/problems/meeting-schedule-ii
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int len = intervals.size();

        if(len == 0)
            return 0;
        
        vector<int> start_times(len);
        vector<int> end_times(len);

        for(int i = 0; i < len; ++i) {
            start_times[i] = intervals[i].start;
            end_times[i] = intervals[i].end;
        }
        
        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());

        int s = 0; 
        int e = 0; 
        int rooms = 0, max_rooms = 0;

        while (s < len) {
            if (start_times[s] < end_times[e]) {
                rooms++;     // a new meeting starts before the earliest one ends
                s++;
            } else {
                rooms--;     // a meeting has ended, free up a room
                e++;
            }
            max_rooms = max(max_rooms, rooms);
        }

        return max_rooms;
    }
};
