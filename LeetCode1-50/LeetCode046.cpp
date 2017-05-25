//
// Created by 房籽呈 on 2017/5/25.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72742252
 */

/**
 * 自己实现 13ms
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums);
        for (;;) {
            int id = -1;
            for (int i = nums.size() - 1; i > 0; --i) {
                if (nums[i] > nums[i - 1]) {
                    id = i - 1;
                    break;
                }
            }
            if (id == -1) {
                break;
            }
            for (int i = nums.size() - 1;; --i) {
                if (nums[i] > nums[id]) {
                    swap(nums[i], nums[id]);
                    reverse(nums.begin() + id + 1, nums.end());
                    break;
                }
            }
            ans.push_back(nums);
        }
        return ans;
    }
};

/**
 * 偷懒用next_permutation 19ms
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums);
        while (next_permutation(nums.begin(), nums.end())) {
            ans.push_back(nums);
        }
        return ans;
    }
};