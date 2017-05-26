//
// Created by 房籽呈 on 2017/5/26.
//

/**
 * 题意：
 * http://blog.csdn.net/houserabbit/article/details/72764439
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(vector<int>(n));
        }
        int num = 1;
        for (int i = 0; i < n / 2; ++i) {
            int m = n - i * 2;
            for (int j = 0; j < m - 1; ++j) ans[i][i + j] = num++;
            for (int j = 0; j < m - 1; ++j) ans[i + j][i + m - 1] = num++;
            for (int j = m - 1; j > 0; --j) ans[i + m - 1][i + j] = num++;
            for (int j = m - 1; j > 0; --j) ans[i + j][i] = num++;
        }
        if (n & 1) {
            ans[n / 2][n / 2] = num++;
        }
        return ans;
    }
};