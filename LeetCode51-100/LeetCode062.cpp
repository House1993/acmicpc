//
// Created by 房籽呈 on 2017/5/31.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72822831
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dn = n + m - 2;
        int up = min(n - 1, dn - n + 1);
        if (up == 0) {
            return 1;
        }
        long long ans = 1;
        for (int i = 1; i <= up; ++i) {
            ans = ans * (dn - i + 1) / i;
        }
        return (int) ans;
    }
};