//
// Created by 房籽呈 on 2017/5/25.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72742983
 */

#define N 26

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        int n = strs.size();
        node f[n];
        for (int i = 0; i < n; ++i) {
            f[i].index = i;
            for (int j = 0; j < N; ++j) {
                f[i].count[j] = 0;
            }
            for (int j = 0; j < strs[i].size(); ++j) {
                ++f[i].count[(int) strs[i][j] - 'a'];
            }
        }
        sort(f, f + n);
        vector<vector<string>> ans;
        for (int i = 0; i < n;) {
            vector<string> part;
            part.push_back(strs[f[i].index]);
            bool isbreak = false;
            for (int j = i + 1; j < n; ++j) {
                if (f[i] == f[j]) {
                    part.push_back(strs[f[j].index]);
                } else {
                    isbreak = true;
                    i = j;
                    break;
                }
            }
            ans.push_back(part);
            if (!isbreak) {
                break;
            }
        }
        return ans;
    }

private:
    struct node {
        int index;
        int count[N];

        bool operator<(const node ff) const {
            for (int i = 0; i < N; ++i) {
                if (count[i] != ff.count[i]) {
                    return count[i] < ff.count[i];
                }
            }
            return false;
        }

        bool operator==(const node ff) const {
            for (int i = 0; i < N; ++i) {
                if (count[i] != ff.count[i]) {
                    return false;
                }
            }
            return true;
        }
    };
};