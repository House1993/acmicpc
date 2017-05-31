//
// Created by 房籽呈 on 2017/5/31.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72823048
 */

class Solution {
public:
    bool isNumber(string s) {
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        int pos = s.find("e");
        if (pos == -1) {
            return isFloat(s);
        }
        return isFloat(s.substr(0, pos)) && isInt(s.substr(pos + 1));
    }

private:
    bool isFloat(string s) {
        int n = s.size();
        if (n == 0) {
            return false;
        }
        bool point = false;
        bool number = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                number = true;
            } else if (s[i] == '+' || s[i] == '-') {
                if (i != 0) {
                    return false;
                }
            } else if (s[i] == '.') {
                if (point) {
                    return false;
                }
                point = true;
            } else {
                return false;
            }
        }
        return number;
    }

    bool isInt(string s) {
        int n = s.size();
        if (n == 0) {
            return false;
        }
        bool number = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                number = true;
            } else if (s[i] == '+' || s[i] == '-') {
                if (i != 0) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return number;
    }
};