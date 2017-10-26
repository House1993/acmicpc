//
// Created by 房籽呈 on 2017/10/26.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/78354033
 */

class Solution {
public:
    int climbStairs(int n) {
        int dp[3];
        dp[1] = dp[2] = 0;
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            int tmp = dp[i % 3];
            dp[i % 3] = 0;
            dp[(i + 1) % 3] += tmp;
            dp[(i + 2) % 3] += tmp;
        }
        return dp[n % 3];
    }
};