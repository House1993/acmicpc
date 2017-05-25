//
// Created by 房籽呈 on 2017/5/25.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72736549
 */

class Solution {
public:
    int jump(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }
        int pos = 0, arr = 0;
        int cnt = 0;
        while (pos < n) {
            int next = 0;
            while (pos < n && pos <= arr) {
                next = max(pos + nums[pos], next);
                ++pos;
            }
            arr = next;
            ++cnt;
        }
        return cnt - 1;
    }
};