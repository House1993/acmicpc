//
// Created by house on 2/16/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/55260240
 */

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (target == nums[mid]) {
                ans = mid;
                break;
            }
            if (nums[l] <= nums[r]) {
                if (target <= nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[l] <= nums[mid]) {
                    if (target >= nums[l] && target <= nums[mid]) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                } else {
                    if (target <= nums[r] && target >= nums[mid]) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
            }
        }
        return ans;
    }
};