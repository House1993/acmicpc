//
// Created by 房籽呈 on 2017/5/26.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72763296
 */

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int ans = nums[0];
        int tmp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            tmp += nums[i];
            ans = max(ans, tmp);
            if (tmp < 0) {
                tmp = 0;
            }
        }
        return ans;
    }
};