//
// Created by 房籽呈 on 2017/1/25.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54783087
 */

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        return unique(nums.begin(), nums.end()) - nums.begin();
    }
};