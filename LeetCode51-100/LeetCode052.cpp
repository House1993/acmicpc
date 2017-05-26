//
// Created by 房籽呈 on 2017/5/26.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72763210
 */

class Solution {
public:
    int totalNQueens(int n) {
        int *column = new int[n];
        int *left = new int[n * 2];
        int *right = new int[n * 2];
        memset(column, 0, sizeof(column));
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        int ans = 0;
        dfs(0, n, column, left, right, &ans);
        return ans;
    }

private:
    void dfs(int row, int total, int *column, int *left, int *right, int *ans) {
        if (row == total) {
            ++(*ans);
            return;
        }
        for (int i = 0; i < total; ++i) {
            int l = i - row + total - 1, r = i + row;
            if (!column[i] && !left[l] && !right[r]) {
                column[i] = left[l] = right[r] = 1;
                dfs(row + 1, total, column, left, right, ans);
                column[i] = left[l] = right[r] = 0;
            }
        }
    }
};