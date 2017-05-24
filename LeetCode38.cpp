//
// Created by 房籽呈 on 2017/5/24.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72676422
 */

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while (--n) {
            stringstream ss;
            int cnt = 1;
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != s[i - 1]) {
                    ss << cnt << s[i - 1];
                    cnt = 1;
                } else {
                    ++cnt;
                }
            }
            ss << cnt << s[s.size() - 1];
            s = ss.str();
        }
        return s;
    }
};