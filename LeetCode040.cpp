//
// Created by 房籽呈 on 2017/5/24.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72677395
 */

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        n = candidates.size();
        count = new int[n];
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        dfs(n - 1, target, ans, candidates);
        return ans;
    }

private:
    int n;
    int *count;

    void dfs(int idx, int target, vector<vector<int>> &ans, vector<int> &candidates) {
        if (candidates[idx] <= target &&
            (idx == n - 1 || candidates[idx] != candidates[idx + 1] || count[idx + 1] == 1)) {
            count[idx] = 1;
            int newtar = target - candidates[idx];
            if (newtar == 0) {
                vector<int> res;
                for (int i = idx; i < n; ++i) {
                    if (count[i] == 1) {
                        res.push_back(candidates[i]);
                    }
                }
                ans.push_back(res);
            } else if (idx > 0) {
                dfs(idx - 1, newtar, ans, candidates);
            }
        }
        count[idx] = 0;
        if (idx > 0) {
            dfs(idx - 1, target, ans, candidates);
        }
    }
};