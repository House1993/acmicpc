//
// Created by 房籽呈 on 2017/5/26.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72763622
 */

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) {
            return true;
        }
        long long arrive = 0;
        for (int i = 0; i <= arrive && i < n; ++i) {
            arrive = max(arrive, (long long) nums[i] + i);
        }
        if (arrive < n - 1) return false;
        return true;
    }
};