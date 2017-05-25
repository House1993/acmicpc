//
// Created by house on 1/9/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54289611
 */

class Solution {
public:
    string longestCommonPrefix(vector <string> &strs) {
        if (strs.size() == 0) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        int ans = 0;
        for (int i = 1;; ++i) {
            bool same = true;
            if (strs[0].size() < i) {
                break;
            }
            char y = strs[0][i - 1];
            for (string x : strs) {
                if (x.size() < i || x[i - 1] != y) {
                    same = false;
                    break;
                }
            }
            if (!same) {
                break;
            }
            ans = i;
        }
        if (ans) {
            return strs[0].substr(0, ans);
        }
        return "";
    }
};