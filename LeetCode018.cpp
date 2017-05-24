//
// Created by 房籽呈 on 2017/1/24.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54707789
 */

class Solution {
public:
    vector <vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector <vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                for (int l = j + 1, r = nums.size() - 1; l < r;) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        ans.push_back(vector < int > {nums[i], nums[j], nums[l], nums[r]});
                        do {
                            ++l;
                        } while (l < r && nums[l] == nums[l - 1]);
                        do {
                            --r;
                        } while (l < r && nums[r] == nums[r + 1]);
                    } else if (sum < target) {
                        do {
                            ++l;
                        } while (l < r && nums[l] == nums[l - 1]);
                    } else {
                        do {
                            --r;
                        } while (l < r && nums[r] == nums[r + 1]);
                    }
                }
            }
        }
        return ans;
    }
};