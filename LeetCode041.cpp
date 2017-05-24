//
// Created by 房籽呈 on 2017/5/24.
//

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                while (nums[i] - 1 != i && nums[i] >= 1 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                    swap(nums[i], nums[nums[i] - 1]);
                }
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};