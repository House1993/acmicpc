//
// Created by 房籽呈 on 2017/5/24.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72677176
 */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
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
        for (int i = 0; i <= target / candidates[idx]; ++i) {
            count[idx] = i;
            int newtar = target - candidates[idx] * i;
            if (newtar == 0) {
                vector<int> res;
                for (int j = idx; j < n; ++j) {
                    for (int k = count[j]; k > 0; --k) {
                        res.push_back(candidates[j]);
                    }
                }
                ans.push_back(res);
            } else if (candidates[0] <= newtar && idx > 0) {
                dfs(idx - 1, newtar, ans, candidates);
            }
        }
    }
};