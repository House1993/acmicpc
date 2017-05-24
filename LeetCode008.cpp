//
// Created by house on 1/9/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54288621
 */

class Solution {
public:
    int myAtoi(string str) {
        bool first = true;
        int sign = 1;
        long long y = 0;
        for (char x : str) {
            if (x == ' ' && first) {
                continue;
            }
            if (x == '-') {
                sign = -sign;
                if (!first) {
                    y = 0;
                    break;
                }
            } else if (x >= '0' && x <= '9') {
                y = y * 10 + (x - '0');
                if (sign == 1 && y > (1L << 31) - 1) {
                    return 2147483647;
                }
                if (sign == -1 && -y < (int) (1L << 31)) {
                    return -2147483648;
                }
            } else {
                if (x == '+' && first) {
                } else {
                    break;
                }
            }
            first = false;
        }
        return y * sign;
    }
};