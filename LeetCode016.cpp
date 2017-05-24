//
// Created by 房籽呈 on 2017/1/24.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54707475
 */

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); ++i) {
            for (int l = i + 1, r = nums.size() - 1; l < r;) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                    if (ans == target) {
                        return target;
                    }
                }
                if (sum < target) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return ans;
    }
};