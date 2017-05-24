//
// Created by house on 2/16/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/55260486
 */

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (l == nums.size() || nums[l] != target) {
            return vector<int> {-1, -1};
        }
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return vector<int> {l, r - 1};
    }
};