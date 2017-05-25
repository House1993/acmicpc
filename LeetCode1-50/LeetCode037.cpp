//
// Created by 房籽呈 on 2017/5/24.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72676210
 */

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        can.clear();
        int besti = 0, bestj = 0, bestcnt = 10;
        for (int i = 0; i < n; ++i) {
            vector<set<int>> tmp;
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != '.') {
                    tmp.push_back(set<int> {});
                    continue;
                }
                set<int> now = candidate(i, j, board);
                int cnt = now.size();
                // if(cnt == 1){
                //     board[i][j] = *(now.begin()) + '1';
                //     tmp.push_back(set<int>{});
                //     continue;
                // }
                tmp.push_back(now);
                if (cnt < bestcnt) {
                    besti = i;
                    bestj = j;
                    bestcnt = cnt;
                }
            }
            can.push_back(tmp);
        }

        if (bestcnt != 10) {
            if (dfs(besti, bestj, board)) {
                printf("success!");
            } else {
                printf("fuck!");
            }
        }
    }

private:
    int n = 9;
    vector<vector<set<int>>> can;

    set<int> candidate(int i, int j, vector<vector<char>> &board) {
        bool app[9];
        memset(app, false, sizeof(app));
        for (int k = 0; k < n; ++k) {
            if (board[i][k] != '.') {
                app[board[i][k] - '1'] = true;
            }
            if (board[k][j] != '.') {
                app[board[k][j] - '1'] = true;
            }
            int di = i / 3 * 3 + k / 3, dj = j / 3 * 3 + k % 3;
            if (board[di][dj] != '.') {
                app[board[di][dj] - '1'] = true;
            }
        }

        set<int> res;
        for (int k = 0; k < n; ++k) {
            if (!app[k]) {
                res.insert(k);
            }
        }
        return res;
    }

    bool dfs(int x, int y, vector<vector<char>> &board) {
        stack<pair<int, int>> effect;
        set<int> now = can[x][y];
        can[x][y].clear();
        for (int k : now) {
            // printf("%d %d %d\n", x + 1, y + 1, k + 1);
            board[x][y] = k + '1';
            for (int i = 0; i < n; ++i) {
                if (i != y && can[x][i].find(k) != can[x][i].end()) {
                    can[x][i].erase(k);
                    effect.push(make_pair(x, i));
                }
                if (i != x && can[i][y].find(k) != can[i][y].end()) {
                    can[i][y].erase(k);
                    effect.push(make_pair(i, y));
                }
                int di = x / 3 * 3 + i / 3, dj = y / 3 * 3 + i % 3;
                if (can[di][dj].find(k) != can[di][dj].end()) {
                    can[di][dj].erase(k);
                    effect.push(make_pair(di, dj));
                }
            }
            int besti = 0, bestj = 0, bestcnt = 10;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (board[i][j] == '.' && can[i][j].size() < bestcnt) {
                        besti = i;
                        bestj = j;
                        bestcnt = can[i][j].size();
                    }
                }
            }
            if (bestcnt != 0) {
                if (bestcnt == 10 || dfs(besti, bestj, board)) {
                    return true;
                }
            }
            while (!effect.empty()) {
                pair<int, int> e = effect.top();
                effect.pop();
                can[e.first][e.second].insert(k);
            }
        }
        board[x][y] = '.';
        can[x][y] = now;
        return false;
    }
};