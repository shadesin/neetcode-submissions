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
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<vector<int>>intr;
        for(auto x : intervals)
        {
            int start = x.start;
            int end = x.end;
            intr.push_back({start, end});
        }
        sort(intr.begin(), intr.end());

        for(int i = 1; i < intr.size(); i++)
        {
            auto x = intr[i - 1];
            auto y = intr[i];

            if(y[0] < x[1]) return false;
        }

        return true;
    }
};
