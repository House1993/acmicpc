//
// Created by house on 1/9/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54289678
 */

class Solution {
public:
    vector <vector<int>> threeSum(vector<int> &nums) {
        vector <vector<int>> ans;
        map<long long, int> cnt;
        for (int x : nums) {
            ++cnt[x];
        }
        for (map<long long, int>::iterator it1 = cnt.begin(); it1 != cnt.end(); ++it1) {
            int x = it1->first;
            --cnt[x];
            for (auto it2 = it1; it2 != cnt.end(); ++it2) {
                if (it2->second) {
                    int y = it2->first;
                    --cnt[y];
                    long long sum = (long long) x + y;
                    if (-sum >= y && cnt.count(-sum) && cnt[-sum] > 0) {
                        vector<int> tmp{x, y, -sum};
                        ans.push_back(tmp);
                    }
                    ++cnt[y];
                }
            }
            ++cnt[x];
        }
        return ans;
    }
};