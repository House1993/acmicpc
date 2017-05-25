//
// Created by 房籽呈 on 2017/1/24.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54707983
 */

class Solution {
public:
    bool isValid(string s) {
        int const n = s.size();
        if (n & 1) {
            return false;
        }
        char st[n];
        int top = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st[top++] = s[i];
            } else {
                if (top > 0 && match(st[top - 1], s[i])) {
                    --top;
                } else {
                    return false;
                }
            }
        }
        return top == 0;
    }

private:
    bool match(char x, char y) {
        switch (x) {
            case '(':
                return y == ')';
            case '[':
                return y == ']';
            case '{':
                return y == '}';
            default:
                return false;
        }
        return false;
    }
};