//
// Created by 房籽呈 on 2017/1/25.
//

/**
 * 题意：
 * http://blog.csdn.net/houserabbit/article/details/54783137
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return 2147483647;
        }
        bool positive = (dividend ^ divisor) >= 0;
        long long ans = 0, d = dividend, f = divisor;
        int shift = 31;
        for (d = d >= 0 ? d : -d, f = f >= 0 ? f : -f; d >= f; --shift) {
            if (d >= f << shift) {
                d -= f << shift;
                ans += 1L << shift;
            }
        }
        ans = positive ? ans : -ans;
        return ans >= 2147483647 ? 2147483647 : ans;
    }
};