//
// Created by 房籽呈 on 2017/5/25.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72758088
 */

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        int *column = new int[n];
        vector<vector<string>> ans;
        dfs(0, n, column, ans);
        return ans;
    }

private:
    void dfs(int row, int total, int *column, vector<vector<string>> &ans) {
        if (row == total) {
            vector<string> part;
            for (int i = 0; i < total; ++i) {
                stringstream ss;
                for (int j = 0; j < total; ++j) {
                    if (column[i] == j) {
                        ss << 'Q';
                    } else {
                        ss << '.';
                    }
                }
                part.push_back(ss.str());
            }
            ans.push_back(part);
            return;
        }
        for (int i = 0; i < total; ++i) {
            bool can = true;
            for (int j = 0; j < row; ++j) {
                if (i == column[j] || i == column[j] - (row - j) || i == column[j] + (row - j)) {
                    can = false;
                    break;
                }
            }
            if (can) {
                column[row] = i;
                dfs(row + 1, total, column, ans);
            }
        }
    }
};