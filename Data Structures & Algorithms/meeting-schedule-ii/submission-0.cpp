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
        int n = intervals.size();
        vector<int>start, end;

        for(auto x : intervals)
        {
            start.push_back(x.start);
            end.push_back(x.end); 
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());


        int global = 0, local = 0;

        int e = 0;

        for(int s = 0; s < n; s++)
        {
            if(start[s] < end[e])
            {
                local++;
                global = max(global, local);
                continue;
            }
            s--;
            e++;
            local--;
        }

        return global;
    }
};
