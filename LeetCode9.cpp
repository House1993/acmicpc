//
// Created by house on 1/9/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54288784
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x == 0) {
            return true;
        }
        int l = 1000000000;
        while (x / l == 0) {
            l /= 10;
        }
        int r = 1;
        while (l > r) {
            if (x / l % 10 != x / r % 10) {
                return false;
            }
            l /= 10;
            r *= 10;
        }
        return true;
    }
};