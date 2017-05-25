//
// Created by 房籽呈 on 2017/5/25.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72743509
 */

class Solution {
public:
    double myPow(double x, int n) {
        if (x > -1e-8 && x < 1e-8) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        long long up = n;
        if (up < 0) {
            x = 1.0 / x;
            up = -up;
        }
        double y = 1.0;
        while (up) {
            if (up & 1) {
                y *= x;
            }
            x *= x;
            up >>= 1;
        }
        return y;
    }
};