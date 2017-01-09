//
// Created by house on 1/9/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54289539
 */

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> toint;
        toint['I'] = 1;
        toint['V'] = 5;
        toint['X'] = 10;
        toint['L'] = 50;
        toint['C'] = 100;
        toint['D'] = 500;
        toint['M'] = 1000;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            int cur = toint[s[i]];
            int nex = -1;
            if (i + 1 < s.size() && toint[s[i + 1]] > cur) {
                cur = -cur;
            }
            ans += cur;
        }
        return ans;
    }
};