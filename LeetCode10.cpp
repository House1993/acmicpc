//
// Created by house on 1/9/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54288851
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        ch.clear();
        cnt.clear();
        len = 0;
        sl = s.size();
        ss = s;
        for (int i = 0; i < p.size(); ++i) {
            ++len;
            ch.push_back(p[i]);
            if (i + 1 < p.size() && p[i + 1] == '*') {
                ++i;
                cnt.push_back(-1);
            } else {
                cnt.push_back(1);
            }
        }
        return dfs(0, 0);
    }

private:
    vector<char> ch;
    vector<int> cnt;
    int len;
    int sl;
    string ss;

    bool dfs(int si, int ci) {
        if (si == sl && ci == len) {
            return true;
        } else if (si == sl && ci != len) {
            for (int i = ci; i < len; ++i) {
                if (cnt[i] != -1) {
                    return false;
                }
            }
            return true;
        } else if (si != sl && ci == len) {
            return false;
        }
        if (cnt[ci] != -1) {
            if (ch[ci] != '.') {
                for (int i = 0; i < cnt[ci]; ++i) {
                    if (ss[si + i] != ch[ci]) {
                        return false;
                    }
                }
            }
            return dfs(si + cnt[ci], ci + 1);
        }
        for (int i = 0; i <= sl - si; ++i) {
            if (i == 0 || ch[ci] == '.' || ss[si + i - 1] == ch[ci]) {
                if (dfs(si + i, ci + 1)) {
                    return true;
                }
            } else {
                break;
            }
        }
        return false;
    }
};