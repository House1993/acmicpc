//
// Created by 房籽呈 on 2017/5/25.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72731255
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        if (m == 0 && n == 0) return true;
        if (n == 0) return false;
        bool L[n];
        memset(L, false, sizeof(L));
        L[0] = true;
        for (int i = 1; i < n; ++i) {
            if (L[i - 1] && p[i - 1] == '*') {
                L[i] = true;
            } else {
                break;
            }
        }
        if (m == 0) return L[n - 1] && p[n - 1] == '*';
        bool dp[n][m];
        memset(dp, false, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (p[i] == '*') {
                    if (i == 0 && j == 0) {
                        dp[i][j] = true;
                    } else if (i == 0) {
                        dp[i][j] = true;
                    } else if (j == 0) {
                        if (L[i] || dp[i - 1][j]) {
                            dp[i][j] = true;
                        }
                    } else if (dp[i - 1][j - 1] || dp[i][j - 1] || dp[i - 1][j]) {
                        dp[i][j] = true;
                    }
                } else if (p[i] == '?' || p[i] == s[j]) {
                    if (i == 0 && j == 0) {
                        dp[i][j] = true;
                    } else if (i == 0) {
                    } else if (j == 0) {
                        if (L[i]) {
                            dp[i][j] = true;
                        }
                    } else if (dp[i - 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};