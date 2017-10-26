//
// Created by 房籽呈 on 2017/6/19.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/73468093
 */

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int ans = 1;
        int i = 2;
        while (x != 1) {
            int i2 = i * i;
            while (x % i2 == 0) {
                x /= i2;
                ans *= i;
            }
            ++i;
        }
        return ans;
    }
};