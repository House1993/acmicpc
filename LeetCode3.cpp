//
// Created by house on 1/9/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54287680
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<char> qu;
        bool pos[256];
        memset(pos, false, sizeof(pos));
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (pos[s[i]]) {
                while (qu.front() != s[i]) {
                    pos[qu.front()] = false;
                    qu.pop();
                }
                qu.pop();
            }
            qu.push(s[i]);
            pos[s[i]] = true;
            if (qu.size() > ans) {
                ans = qu.size();
            }
        }
        return ans;
    }
};