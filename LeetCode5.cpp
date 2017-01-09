//
// Created by house on 1/9/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54288158
 */

class Solution {
public:
    string longestPalindrome(string s) {
        stringstream ss;
        ss << "#";
        for (char x:s) {
            ss << x << "#";
        }
        ss << "#";
        string f = ss.str();
        int ans = 0, max_pos = 0;
        int pos = 0, max_right = 0;
        int pal[f.size()];
        memset(pal, 0, sizeof(pal));
        for (int i = 0; i < f.size(); ++i) {
            if (i < max_right) {
                pal[i] = min(pal[pos * 2 - i], max_right - i);
            } else {
                pal[i] = 1;
            }
            for (int j = pal[i] + 1; i - j + 1 >= 0 && i + j - 1 < f.size() && f[i - j + 1] == f[i + j - 1]; ++j) {
                pal[i] = j;
            }
            if (i + pal[i] - 1 > max_right) {
                max_right = i + pal[i] - 1;
                pos = i;
            }
            if (pal[i] - 1 > ans) {
                ans = pal[i] - 1;
                max_pos = i;
            }
        }
        printf("%d %d\n", max_pos, ans);
        return s.substr((max_pos - pal[max_pos] + 1) / 2, ans);
    }
};