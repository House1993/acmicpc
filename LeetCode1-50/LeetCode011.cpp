//
// Created by house on 1/9/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54289319
 */

class Solution {
public:
    int maxArea(vector<int> &height) {
        int ans = 0;
        vector <pair<int, int>> rank;
        for (int i = 0; i < height.size(); ++i) {
            rank.push_back(make_pair(height[i], i));
        }
        sort(rank.begin(), rank.end());
        int l, r;
        l = r = rank.rbegin()->second;
        for (int i = rank.size() - 2; i >= 0; --i) {
            int pos = rank[i].second, w = 0;
            if (pos < l) {
                w = r - pos;
                l = pos;
            } else if (pos > r) {
                w = pos - l;
                r = pos;
            } else {
                w = max(r - pos, pos - l);
            }
            if (ans < w * rank[i].first) {
                ans = w * rank[i].first;
            }
        }
        return ans;
    }
};