//
// Created by 房籽呈 on 2017/5/24.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72683376
 */

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                while (nums[i] - 1 != i && nums[i] >= 1 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                    swap(nums[i], nums[nums[i] - 1]);
                }
            }
            while (ans < nums.size() && nums[ans] == ans + 1) {
                ++ans;
            }
        }
        return ans + 1;
    }
};