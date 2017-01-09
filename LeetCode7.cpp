//
// Created by house on 1/9/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54288549
 */

class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x = -x;
        }
        long long y = 0;
        while (x) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        if (y > (1L << 31) - 1 || y < (int) (1L << 31)) {
            y = 0;
        }
        return y * sign;
    }
};