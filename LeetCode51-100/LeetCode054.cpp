//
// Created by 房籽呈 on 2017/5/26.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72763411
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> ans;
        int rows = matrix.size();
        if (rows == 0) {
            return ans;
        }
        int columns = matrix[0].size();
        for (int i = 0; rows > 0 && columns > 0; ++i, rows -= 2, columns -= 2) {
            if (rows == 1) {
                for (int j = 0; j < columns; ++j) {
                    ans.push_back(matrix[i][j + i]);
                }
            } else if (columns == 1) {
                for (int j = 0; j < rows; ++j) {
                    ans.push_back(matrix[i + j][i]);
                }
            } else {
                for (int j = 0; j < columns; ++j) {
                    ans.push_back(matrix[i][i + j]);
                }
                for (int j = 1; j < rows - 1; ++j) {
                    ans.push_back(matrix[i + j][i + columns - 1]);
                }
                for (int j = columns - 1; j >= 0; --j) {
                    ans.push_back(matrix[i + rows - 1][i + j]);
                }
                for (int j = rows - 2; j >= 1; --j) {
                    ans.push_back(matrix[i + j][i]);
                }
            }
        }
        return ans;
    }
};