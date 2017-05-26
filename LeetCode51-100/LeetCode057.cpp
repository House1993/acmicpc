//
// Created by 房籽呈 on 2017/5/26.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72764246
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ans;
        if (intervals.size() == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        int s = newInterval.start, e = newInterval.end;
        bool in = false, insert = false;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].end < s) {
                ans.push_back(intervals[i]);
            } else if (intervals[i].start > e) {
                if (!insert) {
                    insert = true;
                    in = false;
                    ans.push_back(Interval(s, e));
                }
                ans.push_back(intervals[i]);
            } else {
                in = true;
                s = min(s, intervals[i].start);
                e = max(e, intervals[i].end);
            }
        }
        if (!insert && (in || intervals[intervals.size() - 1].end < s)) {
            ans.push_back(Interval(s, e));
        }
        return ans;
    }
};