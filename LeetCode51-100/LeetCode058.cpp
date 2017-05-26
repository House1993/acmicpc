//
// Created by 房籽呈 on 2017/5/26.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72764344
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        for (--n; n >= 0 && s[n] == ' '; --n);
        for (int i = n;; --i) {
            if (i < 0 || s[i] == ' ') {
                return n - i;
            }
        }
        return 0;
    }
};