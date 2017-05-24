//
// Created by 房籽呈 on 2017/4/28.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72676027
 */

class Solution {
public:
    bool isValidSudoku(vector <vector<char>> &board) {
        const int step = 3;
        bool app[step * step];

        for (int i = 0; i < step * step; ++i) {

            memset(app, 0, sizeof(app));
            for (int j = 0; j < step * step; ++j) {
                if (board[i][j] != '.') {
                    if (app[board[i][j] - '1']) {
                        return false;
                    } else {
                        app[board[i][j] - '1'] = true;
                    }
                }
            }

            memset(app, 0, sizeof(app));
            for (int j = 0; j < step * step; ++j) {
                if (board[j][i] != '.') {
                    if (app[board[j][i] - '1']) {
                        return false;
                    } else {
                        app[board[j][i] - '1'] = true;
                    }
                }
            }

            memset(app, 0, sizeof(app));
            int x = i / 3 * 3, y = i % 3 * 3;
            for (int j = 0; j < step * step; ++j) {
                int dx = j / 3 + x, dy = j % 3 + y;
                if (board[dx][dy] != '.') {
                    if (app[board[dx][dy] - '1']) {
                        return false;
                    } else {
                        app[board[dx][dy] - '1'] = true;
                    }
                }
            }

        }

        return true;
    }

};