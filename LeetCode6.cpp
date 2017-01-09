//
// Created by house on 1/9/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54288450
 */

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        stringstream ss;
        if (numRows == 2) {
            for (int i = 0; i < s.size(); i += 2) {
                ss << s[i];
            }
            for (int i = 1; i < s.size(); i += 2) {
                ss << s[i];
            }
            return ss.str();
        }
        int cir = numRows + numRows - 2;
        for (int i = 0; i < s.size(); i += cir) {
            ss << s[i];
        }
        for (int j = 1; j < numRows - 1; ++j) {
            int neighbor = cir - j - j;
            for (int i = j; i < s.size(); i += cir) {
                ss << s[i];
                if (i + neighbor < s.size()) {
                    ss << s[i + neighbor];
                }
            }
        }
        for (int i = numRows - 1; i < s.size(); i += cir) {
            ss << s[i];
        }
        return ss.str();
    }
};