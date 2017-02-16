//
// Created by house on 2/16/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/55260041
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), ans = 0;
        int left = 0, pos = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++left;
            } else {
                if (left > 0) {
                    --left;
                    if (left == 0) {
                        ans = max(ans, i - pos);
                    }
                } else {
                    pos = i;
                }
            }
        }
        left = 0, pos = n;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')') {
                ++left;
            } else {
                if (left > 0) {
                    --left;
                    if (left == 0) {
                        ans = max(ans, pos - i);
                    }
                } else {
                    pos = i;
                }
            }
        }
        return ans;
    }
};