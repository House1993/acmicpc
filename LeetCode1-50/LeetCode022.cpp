//
// Created by 房籽呈 on 2017/1/24.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54783019
 */

class Solution {
public:
    vector <string> generateParenthesis(int n) {
        set <string> tmp{""};
        while (n--) {
            tmp = grow(tmp);
        }
        vector <string> ans;
        for (auto it : tmp) {
            ans.push_back(it);
        }
        return ans;
    }

private:
    set <string> grow(set <string> &fa) {
        set <string> son;
        for (auto it : fa) {
            son.insert("(" + it + ")");
            for (int i = 0; i < it.size(); ++i) {
                son.insert(it.substr(0, i + 1) + "()" + it.substr(i + 1, it.size() - i - 1));
            }
        }
        return son;
    }
};