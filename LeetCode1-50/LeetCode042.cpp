//
// Created by 房籽呈 on 2017/5/24.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72685987
 */

/**
 * 单调队列版本 9ms
 */
class Solution {
public:
    int trap(vector<int> &height) {
        if (height.size() <= 2) {
            return 0;
        }
        int top = 1;
        int *ht = new int[height.size()];
        int *id = new int[height.size()];
        ht[0] = height[0];
        id[0] = 0;
        int ans = 0;
        for (int i = 1; i < height.size(); ++i) {
            if (height[i] == 0) {
                continue;
            }
            int h = 0;
            while (top > 0 && ht[top - 1] <= height[i]) {
                ans += (min(ht[top - 1], height[i]) - h) * (i - id[top - 1] - 1);
                h = min(ht[top - 1], height[i]);
                --top;
            }
            if (top > 0) {
                ans += (min(ht[top - 1], height[i]) - h) * (i - id[top - 1] - 1);
            }
            ht[top] = height[i];
            id[top] = i;
            ++top;
        }
        return ans;
    }
};

/**
 * 排序版本 12ms
 */
class Solution {
public:
    int trap(vector<int> &height) {
        if (height.size() <= 2) {
            return 0;
        }
        cmp *itm = new cmp[height.size()];
        for (int i = 0; i < height.size(); ++i) {
            itm[i].idx = i;
            itm[i].val = height[i];
        }
        sort(itm, itm + height.size());
        int ans = 0, l = itm[0].idx, r = itm[0].idx;
        for (int i = 1; i < height.size(); ++i) {
            if (itm[i].idx < l) {
                ans += (l - itm[i].idx - 1) * itm[i].val;
                l = itm[i].idx;
            } else if (itm[i].idx > r) {
                ans += (itm[i].idx - r - 1) * itm[i].val;
                r = itm[i].idx;
            } else {
                ans -= itm[i].val;
            }
        }
        return ans;
    }

private:
    struct cmp {
        int idx, val;

        bool operator<(const cmp f) const {
            return val > f.val;
        }
    };
};