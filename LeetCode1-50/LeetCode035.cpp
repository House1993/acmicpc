//
// Created by house on 2/16/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/55260541
 */

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};