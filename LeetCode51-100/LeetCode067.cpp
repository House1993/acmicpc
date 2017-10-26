//
// Created by 房籽呈 on 2017/6/19.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/73468171
 */

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            swap(a, b);
        }
        int i = a.size() - 1;
        int j = b.size() - 1;
        stringstream ss;
        int add = 0;
        while (j >= 0) {
            add += a[i] + b[j] - '0' - '0';
            --i;
            --j;
            ss << (add & 1);
            add >>= 1;
        }
        while (add && i >= 0) {
            add += a[i] - '0';
            --i;
            ss << (add & 1);
            add >>= 1;
        }
        if (add > 0) {
            ss << add;
            string ans = ss.str();
            reverse(ans.begin(), ans.end());
            return ans;
        }
        string ans = ss.str();
        reverse(ans.begin(), ans.end());
        return a.substr(0, i + 1) + ans;
    }
};