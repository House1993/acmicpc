//
// Created by 房籽呈 on 2017/5/26.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72763935
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
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ans;
        int s = intervals[0].start, e = intervals[0].end;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start > e) {
                ans.push_back(Interval(s, e));
                s = intervals[i].start;
                e = intervals[i].end;
            } else {
                e = max(e, intervals[i].end);
            }
        }
        ans.push_back(Interval(s, e));
        return ans;
    }

private:
    static bool cmp(Interval f1, Interval f2) {
        return f1.start < f2.start;
    }
};