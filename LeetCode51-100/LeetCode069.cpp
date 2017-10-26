//
// Created by 房籽呈 on 2017/10/26.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/78353949
 */

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int ans = 1;
        int l = 1, r = x / 2;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (x / mid >= mid) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};